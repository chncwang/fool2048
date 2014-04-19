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

bool HasGameEnded(const FullBoard &full_board) {
  return !IsMovable(full_board, Orientation::kRight) &&
      !IsMovable(full_board, Orientation::kUp);
}

bool IsMovable(const FullBoard &full_board, Orientation orientation) {
  FullBoard copied_full_board;
  copied_full_board.Copy(full_board);
  copied_full_board.PlayMovingMove(orientation);

  return !IsEqual(full_board, copied_full_board);
}
