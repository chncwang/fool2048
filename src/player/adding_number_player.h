/*
 * adding_number_player.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef ADDING_NUMBER_PLAYER_H_
#define ADDING_NUMBER_PLAYER_H_

#include "board/full_board.h"

class AddingNumberPlayer {
public:
  AddingNumberPlayer() = default;

  virtual ~AddingNumberPlayer() {
  }

  virtual AddingNumberMove NextMove(const FullBoard &full_board) const = 0;

  DISALLOW_COPY_AND_ASSIGN(AddingNumberPlayer);
};

#endif /* ADDING_NUMBER_PLAYER_H_ */
