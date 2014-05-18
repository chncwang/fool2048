/*
 * full_board.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#include "board/full_board.h"

#include <cassert>

#include "board/adding_number_move.h"
#include "board/board_helper.h"
#include "board/full_board_game.h"
#include "board/number_util.h"
#include "board/location/location.h"
#include "board/location/location_helper.h"
#include "board/zobrist_hash_factor.h"
#include "log_util.h"

namespace fool2048 {
namespace board {

using location::Location;
using location::Orientation;
using log4cplus::Logger;
using std::ostream;

namespace {

const Logger LOG =
    Logger::getInstance(LOG4CPLUS_TEXT("fool2048.board.FullBoard"));

}

FullBoard::FullBoard() : empty_number_count_(kBoardLengthSquare),
    last_force_(Force::kMoving) { }

void FullBoard::Copy(const FullBoard &full_board) {
  board_.Copy(full_board.board_);
  empty_number_count_ = full_board.empty_number_count_;
  last_force_ = full_board.last_force_;
}

void FullBoard::PlayAddingNumberMove(const AddingNumberMove &move) {
  last_force_ = Force::kAddingNumber;
  board_.SetNumber(move.GetLocation(), move.GetInitialNumber());
  --empty_number_count_;
}

void FullBoard::PlayMovingMove(Orientation orientation) {
  last_force_ = Force::kMoving;

  for (int outter_i = 0; outter_i < kBoardLength; ++outter_i) {
    Location last_number_location;
    bool merge_available = false;
    bool first_number_moved = false;

    for (int inner_i = InnerIndexBegin(orientation);
        inner_i != InnerIndexEnd(orientation);
        inner_i += InnerIndexStep(orientation)) {
      Location current_location = GetLocation(orientation, outter_i, inner_i);
      Number number = board_.GetNumber(current_location);

      LOG_UTIL_DEBUG(LOG, "current_location " << current_location <<
          " number " << number);

      if (number == Board::kEmpty) continue;

      board_.SetNumber(current_location, Board::kEmpty);

      if (merge_available && number == board_.GetNumber(last_number_location)
          && number != Board::kEmpty) {
        LOG_UTIL_DEBUG(LOG, "merge condition: " << "last_number_location " <<
            last_number_location << " number " <<
            GetNumber(last_number_location));

        assert(first_number_moved);
        merge_available = false;
        SetNumberAsDouble(last_number_location);
        ++empty_number_count_;
      } else {
        if (!first_number_moved) {
          LOG_UTIL_DEBUG(LOG, "move first number condition");
          assert(!merge_available);
          first_number_moved = true;
          merge_available = true;
          last_number_location.Copy(
              GetLocation(orientation, outter_i, InnerIndexBegin(orientation)));
        } else {
          LOG_UTIL_DEBUG(LOG, "move other number condition");
          assert(first_number_moved);
          merge_available = true;
          last_number_location.Copy(GetAdjacentLocation(last_number_location,
              OppositeOrientation(orientation)));
        }
        board_.SetNumber(last_number_location, number);
      }
    }
  }
}

HashKey FullBoard::ZobristHash() const {
  ZobristHashFactor *zobrist_hash_factor = ZobristHashFactor::GetInstance();
  HashKey hash_key = zobrist_hash_factor->GetForceFactor(last_force_);

  board_.ForEachLocation([&hash_key, zobrist_hash_factor](
      const Location &location, Number number) {
    hash_key ^= zobrist_hash_factor->GetLocationFactor(location, number);
  });

  return hash_key;
}

int FullBoard::ResultLevel() const {
  assert(HasGameEnded(*this));

  Number max = 0;
  board_.ForEachLocation([&max](const Location &location,
      Number number) {
    if (max < number) {
      max = number;
    }
  });

  return GetLevel(max);
}

void FullBoard::SetNumberAsDouble(const Location &location) {
  ValidateBeforeSetDouble(location);
  board_.SetNumber(location, board_.GetNumber(location) << 1);
}

void FullBoard::ValidateBeforeSetDouble(const Location &location) const {
  Number number = board_.GetNumber(location);
  LOG_UTIL_DEBUG(LOG, "location " << location << " number " << number);
  assert(number > 0 && number < kMaxPossibleNumber
      && (number & (number - 1)) == 0);
}

ostream& operator<<(ostream & out, const FullBoard &full_board) {
  return out << "[" << full_board.board_ << ", empty_number_count_: "
      << full_board.empty_number_count_ << ", last_force_ " <<
      full_board.last_force_ << "]";
}

bool IsEqual(const FullBoard &a, const FullBoard &b) {
  bool is_board_equal = IsEqual(a.board_, b.board_);
  if (is_board_equal) {
    assert(a.empty_number_count_ == b.empty_number_count_);
  }
  return is_board_equal && a.last_force_ == b.last_force_;
}

}
}
