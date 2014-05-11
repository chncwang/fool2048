/*
 * board_helper.h
 *
 *  Created on: Mar 29, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_BOARD_HELPER_H_
#define SRC_BOARD_BOARD_HELPER_H_

#include "board/location/location.h"
#include "board/def.h"
#include "board/location/orientation.h"

namespace fool2048 {
namespace board {

class Board;

Number GetBoardNumber(const Board &board, int index);

Number GetBoardNumber(const Board &board, int x, int y);

void SetBoardNumber(Board *board, int x, int y, Number number);

int InnerIndexBegin(location::Orientation orientation);

int InnerIndexEnd(location::Orientation orientation);

int InnerIndexStep(location::Orientation orientation);

location::Location
GetLocation(location::Orientation orientation, int outter_index, int inner_index);

}
}

#endif /* SRC_BOARD_BOARD_HELPER_H_ */
