/*
 * full_board_game.h
 *
 *  Created on: Apr 9, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_GAME_H_
#define FULL_BOARD_GAME_H_

#include <bitset>

class FullBoard;

bool HasGameEnded(const FullBoard &full_board);

std::bitset<4> MovableOrientations(const FullBoard &full_board);

#endif /* FULL_BOARD_GAME_H_ */
