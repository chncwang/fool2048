/*
 * full_board_helper.h
 *
 *  Created on: Mar 25, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_HELPER_H_
#define FULL_BOARD_HELPER_H_

#include "full_board.h"


inline Board::Number GetFullBoardNumber(const FullBoard &full_board, int index) {
  return full_board.GetNumber(Board::ToLocation(index));
}


#endif /* FULL_BOARD_HELPER_H_ */
