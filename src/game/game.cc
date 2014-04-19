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
#include "board/orientation.h"

namespace fool2048 {
namespace game {

using board::AddingNumberMove;
using board::Force;
using board::FullBoard;
using board::Orientation;
using std::move;

Game::~Game() {}

void Game::Run() {
  while (!HasGameEnded(full_board_)) {
    if (last_force_ == Force::kMoving) {
      BeforeAddNumber();

      AddingNumberMove
      move = adding_number_player_unique_ptr_->NextMove(full_board_);
      full_board_.PlayAddingNumberMove(move);
    } else {
      BeforeMove();

      Orientation orientation = 
          moving_player_unique_ptr_->NextMove(full_board_);
      full_board_.PlayMovingMove(orientation);
    }

    last_force_ = OppositeForce(last_force_);
  }
}

Game::Game(FullBoard &&full_board,
    AddingNumberPlayerUniquePtr &&adding_number_player_unique_ptr,
    MovingPlayerUniquePtr &&moving_player_unique_ptr) :
    full_board_(move(full_board)),
    adding_number_player_unique_ptr_(move(adding_number_player_unique_ptr)),
    moving_player_unique_ptr_(move(moving_player_unique_ptr)),
    last_force_(Force::kMoving) {}

}
}
