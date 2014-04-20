/*
 * adding_number_player.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef SRC_PLAYER_ADDING_NUMBER_PLAYER_H_
#define SRC_PLAYER_ADDING_NUMBER_PLAYER_H_

#include "board/adding_number_move.h"
#include "player/player.h"

namespace fool2048 {
namespace player {

typedef Player<board::AddingNumberMove> AddingNumberPlayer;

}
}

#endif /* SRC_PLAYER_ADDING_NUMBER_PLAYER_H_ */
