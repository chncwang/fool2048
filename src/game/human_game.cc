/*
 * human_game.cc
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#include "game/human_game.h"

#include <utility>
#include <iostream>

#include "log_util.h"
#include "player/adding_number_randomly_player.h"
#include "player/human_moving_player.h"

using std::cout;
using std::endl;
using std::move;

HumanGame::HumanGame() : HumanGame(FullBoard()) {}

HumanGame::HumanGame(FullBoard &&full_board) : Game(move(full_board),
    move(Game::AddingNumberPlayerUniquePtr(new AddingNumberRandomlyPlayer)),
    move(Game::MovingPlayerUniquePtr(new HumanMovingPlayer))) {}

void HumanGame::BeforeAddNumber() const {
  LOG_UTIL_DEBUG("before add number.");
  FullBoardToStream(cout);
  cout << endl;
}

void HumanGame::BeforeMove() const {
  FullBoardToStream(cout);
  cout << endl;
}
