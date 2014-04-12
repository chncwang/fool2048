/*
 * Player.h
 *
 *  Created on: Apr 7, 2014
 *      Author: chncwang
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "board/full_board.h"

template<typename T>
class Player {
public:
  Player() = default;
  virtual ~Player() {}

  virtual T NextMove(const FullBoard &full_board) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Player);
};

#endif /* PLAYER_H_ */
