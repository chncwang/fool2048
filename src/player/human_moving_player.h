/*
 * human_moving_player.h
 *
 *  Created on: Apr 7, 2014
 *      Author: chncwang
 */

#ifndef HUMAN_MOVING_PLAYER_H_
#define HUMAN_MOVING_PLAYER_H_

#include "board/orientation.h"
#include "player/moving_player.h"

namespace fool2048 {
namespace player {

class HumanMovingPlayer : public MovingPlayer {
public:
  HumanMovingPlayer() = default;
  ~HumanMovingPlayer() = default;

  board::Orientation NextMove(const board::FullBoard &full_board) const;
};

}
}

#endif /* HUMAN_MOVING_PLAYER_H_ */
