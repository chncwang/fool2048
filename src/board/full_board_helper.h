/*
 * full_board_helper.h
 *
 *  Created on: Mar 25, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_FULL_BOARD_HELPER_H_
#define SRC_BOARD_FULL_BOARD_HELPER_H_

#include "def.h"

namespace fool2048 {
namespace board {

class FullBoard;

Number GetFullBoardNumber(const FullBoard &full_board, int index);

Number GetFullBoardNumber(const FullBoard &full_board, int x, int y);

}
}

#endif /* SRC_BOARD_FULL_BOARD_HELPER_H_ */
