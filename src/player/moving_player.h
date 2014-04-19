/*
 * moving_player.h
 *
 *  Created on: Apr 7, 2014
 *      Author: chncwang
 */

#ifndef MOVING_PLAYER_H_
#define MOVING_PLAYER_H_

#include "board/adding_number_move.h"
#include "player/player.h"

namespace fool2048 {
namespace player {

typedef Player<board::Orientation> MovingPlayer;

}
}

#endif /* MOVING_PLAYER_H_ */
