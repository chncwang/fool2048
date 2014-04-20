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
using board::Orientation;
using board::ForEachOrientation;
using std::array;

Orientation MovingRandomlyPlayer::NextMove(const FullBoard &full_board) const {
  assert(!HasGameEnded(full_board));

  array<Orientation, 4> orientation_arr;
  int count = 0;

  ForEachOrientation([&full_board, &orientation_arr, &count]
      (Orientation orientation) {
    if (IsMovable(full_board, orientation)) {
      LOG_UTIL_DEBUG("movable orientation " << orientation);
      orientation_arr.at(count++) = orientation;
    }
  });

  LOG_UTIL_DEBUG("count " << count);
  int rand = NextRandomNumber(count);
  LOG_UTIL_DEBUG("rand " << rand);
  return orientation_arr.at(rand);
}

} /* namespace player */
} /* namespace fool2048 */
