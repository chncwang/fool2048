/*
 * moving_randomly_player.h
 *
 *  Created on: Apr 19, 2014
 *      Author: chncwang
 */

#ifndef SRC_PLAYER_MOVING_RANDOMLY_PLAYER_H_
#define SRC_PLAYER_MOVING_RANDOMLY_PLAYER_H_

#include "board/location/orientation.h"
#include "player/moving_player.h"

namespace fool2048 {
namespace player {

class MovingRandomlyPlayer : public MovingPlayer {
public:
  MovingRandomlyPlayer() = default;
  ~MovingRandomlyPlayer() = default;

  board::location::Orientation NextMove(const board::FullBoard &full_board) const;
};

} /* namespace player */
} /* namespace fool2048 */

#endif /* SRC_PLAYER_MOVING_RANDOMLY_PLAYER_H_ */
