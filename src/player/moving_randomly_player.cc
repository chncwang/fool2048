/*
 * moving_randomly_player.cc
 *
 *  Created on: Apr 19, 2014
 *      Author: chncwang
 */

#include <cassert>

#include <array>

#include "board/full_board_game.h"
#include "log_util.h"
#include "player/moving_randomly_player.h"
#include "rand_util.h"

namespace fool2048 {
namespace player {

using board::FullBoard;
using board::HasGameEnded;
using board::IsMovable;
using board::location::Orientation;
using board::location::ForEachOrientation;
using std::array;
using log4cplus::Logger;

namespace {

Logger LOG = Logger::getInstance(
    LOG4CPLUS_TEXT("fool2048.player.MovingRandomlyPlayer"));

}

Orientation MovingRandomlyPlayer::NextMove(const FullBoard &full_board) const {
  assert(!HasGameEnded(full_board));

  LOG_UTIL_DEBUG(LOG, "full_board " << full_board);

  array<Orientation, 4> orientation_arr;
  int count = 0;

  ForEachOrientation([&full_board, &orientation_arr, &count]
      (Orientation orientation) {
    LOG_UTIL_DEBUG(LOG, "for each loop - orientation " << orientation);
    if (IsMovable(full_board, orientation)) {
      LOG_UTIL_DEBUG(LOG, "movable orientation " << orientation);
      orientation_arr.at(count++) = orientation;
    }
  });

  LOG_UTIL_DEBUG(LOG, "count " << count);
  int rand = NextRandomNumber(count);
  LOG_UTIL_DEBUG(LOG, "rand " << rand);
  return orientation_arr.at(rand);
}

} /* namespace player */
} /* namespace fool2048 */
