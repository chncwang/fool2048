/*
 * human_game.h
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#ifndef SRC_GAME_HUMAN_GAME_H_
#define SRC_GAME_HUMAN_GAME_H_

#include "game/loggable_game.h"

namespace fool2048 {
namespace game {

class HumanGame : public LoggableGame {
public:
  HumanGame(board::FullBoard &&full_board);
  HumanGame(HumanGame&&) = default;
  ~HumanGame() = default;
};

}
}

#endif /* SRC_GAME_HUMAN_GAME_H_ */
