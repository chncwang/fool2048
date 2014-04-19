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
  bool movable = false;

  if (full_board.EmptyNumberCount() > 0) {
    movable = true;
  } else {
    for (int outter_i=0; outter_i<Board::kBoardLength; ++outter_i) {
      Number last_num = -1;
      for (int inner_i=InnerIndexBegin(orientation);
          inner_i != InnerIndexEnd(orientation);
          inner_i += InnerIndexStep(orientation)) {
        Number num =
          full_board.GetNumber(GetLocation(orientation, outter_i, inner_i));

        assert(num !=Board::kEmpty);

        if (num == last_num) {
          movable = true;
          break;
        } else {
          last_num = num;
        }
      }
    }
  }

  return movable;
}
