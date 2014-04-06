/*
 * full_board_helper.h
 *
 *  Created on: Mar 25, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_HELPER_H_
#define FULL_BOARD_HELPER_H_

#include "board/number.h"

class FullBoard;

Number GetFullBoardNumber(const FullBoard &full_board, int index);

#endif /* FULL_BOARD_HELPER_H_ */