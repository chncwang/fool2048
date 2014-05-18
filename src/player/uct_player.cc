/*
 * uct_player.cc
 *
 *  Created on: May 11, 2014
 *      Author: chncwang
 */

#include "player/uct_player.h"

#include <cassert>
#include <cmath>

#include <utility>

#include "board/adding_number_move.h"
#include "board/force.h"
#include "board/full_board_game.h"
#include "board/number_util.h"
#include "game/monte_carlo_game.h"
#include "player/adding_number_randomly_player.h"
#include "log_util.h"

namespace fool2048 {
namespace player {

using board::AddingNumberMove;
using board::FullBoard;
using board::Force;
using board::GetLevel;
using board::HasGameEnded;
using board::HashKey;
using board::IsMovable;
using board::MovableOrientations;
using board::location::Orientation;
using board::location::ForEachOrientation;
using game::MonteCarloGame;
using log4cplus::Logger;
using player::AddingNumberRandomlyPlayer;
using std::make_pair;
using std::move;

namespace {

Logger LOG = Logger::getInstance("fool2048.player.UctPlayer");

void CheckLastForceIs(const FullBoard &full_board, Force force) {
  assert(full_board.LastForce() == force);
}

float GetProfit(const FullBoard &full_board) {
  static int expected_max_level = GetLevel(2048);
  int level = full_board.ResultLevel();

  float profit = (float)level / expected_max_level;

  LOG_UTIL_DEBUG(LOG, "full_board " << full_board << " level " << level <<
      " expected_max_level " << expected_max_level << " profit " << profit);

  return profit;
}

}

const int UctPlayer::kMonteCarloGameCount = 10000;
const HashKey UctPlayer::NodeRecord::kNullHashKey = 0;

Orientation UctPlayer::NextMove(const FullBoard& full_board) const {
  CheckLastForceIs(full_board, Force::kAddingNumber);

  int mc_count = 0;
  while (mc_count < kMonteCarloGameCount) {

    FullBoard current_node;
    Orientation orientation = MaxUcbMove(full_board);
    current_node.Copy(full_board);
    current_node.PlayMovingMove(orientation);
    NewProfit(&current_node, &mc_count);
  }

  return BestChild(full_board);
}

float UctPlayer::NewProfit(board::FullBoard *node,
    int* mc_count) const {
  CheckLastForceIs(*node, Force::kMoving);

  float result;
  HashKey hash_key = node->ZobristHash();
  auto iterator = transposition_table_.find(hash_key);
  if (iterator == transposition_table_.end()) {
    FullBoard copied_node;
    copied_node.Copy(*node);
    MonteCarloGame game(move(copied_node));

    if (!HasGameEnded(*node)) game.Run();

    result = GetProfit(game.GetFullBoard());
    ++(*mc_count);
    NodeRecord node_record(1, result);
    LOG_UTIL_DEBUG(LOG, "node_record " << node_record);
    transposition_table_.insert(make_pair(hash_key, node_record));
  } else {
    NodeRecord *node_record = &(iterator->second);
    int visited_times = node_record->VisitedTimes();
    if (HasGameEnded(*node)) {
      ++(*mc_count);
      result = node_record->AverageProfit();
    } else {
      AddingNumberRandomlyPlayer player;
      AddingNumberMove move = player.NextMove(*node);
      node->PlayAddingNumberMove(move);
      Orientation max_ucb_move = MaxUcbMove(*node);
      node->PlayMovingMove(max_ucb_move);
      float new_profit = NewProfit(node, mc_count);
      LOG_UTIL_DEBUG(LOG, "new_profit " << new_profit);
      float previous_profit = node_record->AverageProfit();
      result = (previous_profit * visited_times + new_profit) /
          (visited_times + 1);
      node_record->SetAverageProfit(result);
    }

    node_record->SetVisitedTimes(visited_times + 1);
  }

  return result;
}

Orientation UctPlayer::BestChild(const board::FullBoard& node) const {
  CheckLastForceIs(node, Force::kAddingNumber);

  auto movable_orientations = MovableOrientations(node);
  int max = -1;
  Orientation best_child;

  for (Orientation orientation : movable_orientations) {
    HashKey hash_key = ChildHashKey(node, orientation);
    auto iterator = transposition_table_.find(hash_key);
    assert(iterator != transposition_table_.end());

    LOG_UTIL_INFO(LOG, "orientation " << orientation << " node_record " <<
        iterator->second);

    int times = iterator->second.VisitedTimes();
    if (times > max) {
      max = times;
      best_child = orientation;
    }
  }

  assert(max > -1);

  return best_child;
}

Orientation UctPlayer::MaxUcbMove(const FullBoard &node) const {
  CheckLastForceIs(node, Force::kAddingNumber);

  int visited_time_sum = 0;

  for (int orientation = 0; orientation < 4; ++orientation) {
    if (!IsMovable(node, static_cast<Orientation>(orientation))) continue;

    HashKey hash_key = ChildHashKey(node,
        static_cast<Orientation>(orientation));
    auto iterator = transposition_table_.find(hash_key);

    if (iterator == transposition_table_.end()) {
      return static_cast<Orientation>(orientation);
    } else {
      visited_time_sum += iterator->second.VisitedTimes();
    }
  }

  float max_ucb = -1.0;
  Orientation result;

  for (int orientation = 0; orientation < 4; ++orientation) {
    if (!IsMovable(node, static_cast<Orientation>(orientation))) continue;

    HashKey hash_key = ChildHashKey(node,
        static_cast<Orientation>(orientation));
    auto iterator = transposition_table_.find(hash_key);
    assert(iterator != transposition_table_.end());

    float ucb = UcbValue(iterator->second, visited_time_sum);
    if (max_ucb < ucb) {

      max_ucb = ucb;
      result = static_cast<Orientation>(orientation);
    }
  }

  return result;
}

HashKey UctPlayer::ChildHashKey(const FullBoard& node,
    Orientation orientation) const {
  CheckLastForceIs(node, Force::kAddingNumber);
  assert(IsMovable(node, orientation));

  FullBoard copied_node;
  copied_node.Copy(node);
  copied_node.PlayMovingMove(orientation);

  return copied_node.ZobristHash();
}

float UctPlayer::UcbValue(const UctPlayer::NodeRecord& node_record,
    int visited_time_sum) const {
  return node_record.AverageProfit() + sqrt(2 * log(visited_time_sum) /
      node_record.VisitedTimes());
}

} /* namespace player */
} /* namespace fool2048 */
