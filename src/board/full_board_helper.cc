/*
 * full_board_helper.cc
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */
#include "full_board_helper.h"

#include "full_board.h"

Number GetFullBoardNumber(const FullBoard &full_board, int index) {
  return full_board.GetNumber(Board::ToLocation(index));
}