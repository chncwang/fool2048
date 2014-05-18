/*
 * loggable_game.h
 *
 *  Created on: May 17, 2014
 *      Author: chncwang
 */

#ifndef SRC_GAME_LOGGABLE_GAME_H_
#define SRC_GAME_LOGGABLE_GAME_H_

#include "board/full_board.h"
#include "game/game.h"

namespace fool2048 {
namespace game {

class LoggableGame : public Game {
public:
  LoggableGame(LoggableGame &&game) = default;
  virtual ~LoggableGame();

protected:
  LoggableGame(board::FullBoard &&full_board,
      AddingNumberPlayerUniquePtr &&adding_number_player,
      MovingPlayerUniquePtr &&moving_player);

  virtual void BeforeAddNumber() const;
  virtual void BeforeMove() const;
};

} /* namespace player */
} /* namespace fool2048 */

#endif /* SRC_GAME_LOGGABLE_GAME_H_ */
