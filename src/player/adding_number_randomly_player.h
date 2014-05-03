/*
 * default_adding_number_player.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef SRC_PLAYER_DEFAULT_ADDING_NUMBER_PLAYER_H_
#define SRC_PLAYER_DEFAULT_ADDING_NUMBER_PLAYER_H_

#include "adding_number_player.h"

namespace fool2048 {
namespace player {

class AddingNumberRandomlyPlayer : public AddingNumberPlayer {
public:
  AddingNumberRandomlyPlayer() = default;
  ~AddingNumberRandomlyPlayer() = default;

  board::AddingNumberMove NextMove(const board::FullBoard &full_board) const;
};

}
}

#endif /* SRC_PLAYER_DEFAULT_ADDING_NUMBER_PLAYER_H_ */
