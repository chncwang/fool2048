/*
 * loggable_game.cc
 *
 *  Created on: May 17, 2014
 *      Author: chncwang
 */

#include "game/loggable_game.h"

#include <utility>

#include "log_util.h"

namespace fool2048 {
namespace game {

using log4cplus::Logger;
using std::move;

namespace {

Logger LOG = Logger::getInstance("fool2048.game.LoggableGame");

}

LoggableGame::~LoggableGame() { }

LoggableGame::LoggableGame(board::FullBoard &&full_board,
    AddingNumberPlayerUniquePtr &&adding_number_player,
    MovingPlayerUniquePtr &&moving_player) : Game(move(full_board),
    move(adding_number_player),
    move(moving_player)) { }

void LoggableGame::BeforeAddNumber() const {
  LOG_UTIL_INFO(LOG, GetFullBoard());
}

void LoggableGame::BeforeMove() const {
  LOG_UTIL_INFO(LOG, GetFullBoard());
}

} /* namespace player */
} /* namespace fool2048 */
