/*
 * board_helper.h
 *
 *  Created on: Mar 29, 2014
 *      Author: chncwang
 */

#ifndef BOARD_HELPER_H_
#define BOARD_HELPER_H_

#include "board/location.h"
#include "board/number.h"
#include "board/orientation.h"

class Board;

Number GetBoardNumber(const Board &board, int index);

Number GetBoardNumber(const Board &board, int x, int y);

void SetBoardNumber(Board *board, int x, int y, Number number);

int InnerIndexBegin(Orientation orientation);

int InnerIndexEnd(Orientation orientation);

int InnerIndexStep(Orientation orientation);

Location
GetLocation(Orientation orientation, int outter_index, int inner_index);

#endif /* BOARD_HELPER_H_ */
