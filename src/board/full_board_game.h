/*
 * full_board_game.h
 *
 *  Created on: Apr 9, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_FULL_BOARD_GAME_H_
#define SRC_BOARD_FULL_BOARD_GAME_H_

#include "orientation.h"

namespace fool2048 {
namespace board {

class FullBoard;

bool HasGameEnded(const FullBoard &full_board);

bool IsMovable(const FullBoard &full_board, Orientation orientation);

}
}

#endif /* SRC_BOARD_FULL_BOARD_GAME_H_ */
