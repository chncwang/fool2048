/*
 * full_board_helper.h
 *
 *  Created on: Mar 25, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_HELPER_H_
#define FULL_BOARD_HELPER_H_

#include "number.h"

namespace fool2048 {
namespace board {

class FullBoard;

Number GetFullBoardNumber(const FullBoard &full_board, int index);

Number GetFullBoardNumber(const FullBoard &full_board, int x, int y);

}
}

#endif /* FULL_BOARD_HELPER_H_ */
