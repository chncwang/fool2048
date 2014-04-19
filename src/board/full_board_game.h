/*
 * full_board_game.h
 *
 *  Created on: Apr 9, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_GAME_H_
#define FULL_BOARD_GAME_H_

#include "orientation.h"

class FullBoard;

bool HasGameEnded(const FullBoard &full_board);

bool IsMovable(const FullBoard &full_board, Orientation orientation);

#endif /* FULL_BOARD_GAME_H_ */
