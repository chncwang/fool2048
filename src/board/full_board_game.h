/*
 * full_board_game.h
 *
 *  Created on: Apr 9, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_FULL_BOARD_GAME_H_
#define SRC_BOARD_FULL_BOARD_GAME_H_

#include <vector>

#include "board/def.h"
#include "board/location/orientation.h"

namespace fool2048 {
namespace board {

class FullBoard;

bool HasGameEnded(const FullBoard &full_board);

bool IsMovable(const FullBoard &full_board, location::Orientation orientation);

std::vector<location::Orientation>
MovableOrientations(const FullBoard &full_board);

}
}

#endif /* SRC_BOARD_FULL_BOARD_GAME_H_ */
