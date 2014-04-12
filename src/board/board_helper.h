/*
 * board_helper.h
 *
 *  Created on: Mar 29, 2014
 *      Author: chncwang
 */

#ifndef BOARD_HELPER_H_
#define BOARD_HELPER_H_

#include "number.h"

class Board;

Number GetBoardNumber(const Board &board, int index);

Number GetBoardNumber(const Board &board, int x, int y);

void SetBoardNumber(Board *board, int x, int y, Number number);

#endif /* BOARD_HELPER_H_ */
