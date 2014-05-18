/*
 * moving_randomly_player.cc
 *
 *  Created on: Apr 19, 2014
 *      Author: chncwang
 */

#include <cassert>

#include "board/full_board_game.h"
#include "log_util.h"
#include "player/moving_randomly_player.h"
#include "rand_util.h"

namespace fool2048 {
namespace player {

using board::FullBoard;
using board::HasGameEnded;
using board::MovableOrientations;
using board::location::Orientation;
using log4cplus::Logger;

namespace {

Logger LOG = Logger::getInstance(
    LOG4CPLUS_TEXT("fool2048.player.MovingRandomlyPlayer"));

}

Orientation MovingRandomlyPlayer::NextMove(const FullBoard &full_board) const {
  assert(!HasGameEnded(full_board));

  LOG_UTIL_DEBUG(LOG, "full_board " << full_board);

  auto orientations = MovableOrientations(full_board);

  int rand = NextRandomNumber(orientations.size());
  LOG_UTIL_DEBUG(LOG, "rand " << rand);
  return orientations.at(rand);
}

} /* namespace player */
} /* namespace fool2048 */
