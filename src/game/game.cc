/*
 * game.cc
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#include "game/game.h"

#include <utility>

#include "board/adding_number_move.h"
#include "board/full_board_game.h"
#include "board/location/orientation.h"
#include "log_util.h"

namespace fool2048 {
namespace game {

using board::AddingNumberMove;
using board::Force;
using board::FullBoard;
using board::location::Orientation;
using log4cplus::Logger;
using std::move;

namespace {

const Logger LOG = Logger::getInstance("fool2048.game.Game");

}

Game::~Game() { }

void Game::Run() {
  while (!HasGameEnded(full_board_)) {
    if (full_board_.LastForce() == Force::kMoving) {
      BeforeAddNumber();

      AddingNumberMove
      move = adding_number_player_unique_ptr_->NextMove(full_board_);
      LOG_UTIL_DEBUG(LOG, "move " << move);
      full_board_.PlayAddingNumberMove(move);
    } else {
      BeforeMove();

      Orientation orientation =
          moving_player_unique_ptr_->NextMove(full_board_);
      LOG_UTIL_DEBUG(LOG, "orientation " << orientation);
      full_board_.PlayMovingMove(orientation);
    }
  }
}

Game::Game(FullBoard &&full_board,
    AddingNumberPlayerUniquePtr &&adding_number_player_unique_ptr,
    MovingPlayerUniquePtr &&moving_player_unique_ptr) :
    full_board_(move(full_board)),
    adding_number_player_unique_ptr_(move(adding_number_player_unique_ptr)),
    moving_player_unique_ptr_(move(moving_player_unique_ptr)) { }

}
}
