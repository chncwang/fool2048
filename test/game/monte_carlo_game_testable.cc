/*
 * monte_carlo_game_testable.cc
 *
 *  Created on: May 2, 2014
 *      Author: chncwang
 */

#include "game/monte_carlo_game_testable.h"

#include <iostream>
#include <utility>

#include "log_util.h"

namespace fool2048 {
namespace game {

using log4cplus::Logger;
using std::cout;
using std::endl;
using std::move;

namespace {

const Logger LOG = Logger::getInstance("fool2048.game.MonteCarloGameTestable");

}

MonteCarloGameTestable::MonteCarloGameTestable(board::FullBoard &&full_board,
    board::Force force) : MonteCarloGame(move(full_board), force) { }

void MonteCarloGameTestable::BeforeAddNumber() const {
  LOG_UTIL_INFO(GetFullBoard());
}

void MonteCarloGameTestable::BeforeMove() const {
  LOG_UTIL_INFO(GetFullBoard());
}

} /* namespace game */
} /* namespace fool2048 */
