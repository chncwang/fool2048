/*
 * full_board_game.cc
 *
 *  Created on: Apr 9, 2014
 *      Author: chncwang
 */

#include "full_board_game.h"

#include "board/number.h"
#include "board/board_helper.h"
#include "full_board.h"
#include "location_helper.h"

namespace fool2048 {
namespace board {

bool HasGameEnded(const FullBoard &full_board) {
  bool ended = true;

  if (full_board.EmptyNumberCount() > 0) {
    ended = false;
  } else {
    for (int i=0; i<4; ++i) {
      if (IsMovable(full_board, static_cast<Orientation>(i))) {
        ended = false;
        break;
      }
    }
  }

  return ended;
}

bool IsMovable(const FullBoard &full_board, Orientation orientation) {
  FullBoard copied_full_board;
  copied_full_board.Copy(full_board);
  copied_full_board.PlayMovingMove(orientation);

  return !IsEqual(full_board, copied_full_board);
}

}
}
