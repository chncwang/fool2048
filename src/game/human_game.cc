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

namespace fool2048 {
namespace game {

using board::FullBoard;
using board::Force;
using player::AddingNumberRandomlyPlayer;
using player::HumanMovingPlayer;
using std::cout;
using std::endl;
using std::move;
using log4cplus::Logger;

namespace {

Logger LOG = Logger::getInstance(LOG4CPLUS_TEXT("fool2048.game.HumanGame"));

}

HumanGame::HumanGame(FullBoard &&full_board, Force last_force) :
    Game(move(full_board),
    last_force,
    move(Game::AddingNumberPlayerUniquePtr(new AddingNumberRandomlyPlayer)),
    move(Game::MovingPlayerUniquePtr(new HumanMovingPlayer))) {}

void HumanGame::BeforeAddNumber() const {
  LOG_UTIL_TRACE("before add number.");
  LOG_UTIL_INFO(GetFullBoard());
}

void HumanGame::BeforeMove() const {
  LOG_UTIL_INFO(GetFullBoard());
}

}
}
