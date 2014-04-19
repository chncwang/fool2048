/*
 * moving_randomly_player.h
 *
 *  Created on: Apr 19, 2014
 *      Author: chncwang
 */

#ifndef MOVING_RANDOMLY_PLAYER_H_
#define MOVING_RANDOMLY_PLAYER_H_

namespace fool2048 {
namespace player {

class MovingRandomlyPlayer {
public:
  MovingRandomlyPlayer() = default;
  ~MovingRandomlyPlayer() = default;

  board::Orientation NextMove(const board::FullBoard &full_board) const;
};

} /* namespace player */
} /* namespace fool2048 */

#endif /* MOVING_RANDOMLY_PLAYER_H_ */
