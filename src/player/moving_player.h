/*
 * moving_player.h
 *
 *  Created on: Apr 7, 2014
 *      Author: chncwang
 */

#ifndef SRC_PLAYER_MOVING_PLAYER_H_
#define SRC_PLAYER_MOVING_PLAYER_H_

#include "board/adding_number_move.h"
#include "player/player.h"

namespace fool2048 {
namespace player {

typedef Player<board::Orientation> MovingPlayer;

}
}

#endif /* SRC_PLAYER_MOVING_PLAYER_H_ */
