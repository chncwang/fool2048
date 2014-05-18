/*
 * auto_game.h
 *
 *  Created on: May 17, 2014
 *      Author: chncwang
 */

#ifndef SRC_GAME_AUTO_GAME_H_
#define SRC_GAME_AUTO_GAME_H_

#include "game/loggable_game.h"

namespace fool2048 {
namespace game {

class AutoGame : public LoggableGame {
public:
  AutoGame(board::FullBoard &&full_board);
  AutoGame(AutoGame &&auto_game) = default;
  ~AutoGame() = default;
};

} /* namespace player */
} /* namespace fool2048 */

#endif /* SRC_GAME_AUTO_GAME_H_ */
