/*
 * Player.h
 *
 *  Created on: Apr 7, 2014
 *      Author: chncwang
 */

#ifndef SRC_PLAYER_PLAYER_H_
#define SRC_PLAYER_PLAYER_H_

#include "board/full_board.h"

namespace fool2048 {
namespace player {

template<typename T>
class Player {
public:
  Player() = default;
  virtual ~Player() {}

  virtual T NextMove(const board::FullBoard &full_board) const = 0;

  DISALLOW_COPY_AND_ASSIGN(Player);
};

}
}

#endif /* SRC_PLAYER_PLAYER_H_ */
