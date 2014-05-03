/*
 * human_game.h
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#ifndef SRC_GAME_HUMAN_GAME_H_
#define SRC_GAME_HUMAN_GAME_H_

#include "def.h"
#include "game/game.h"

namespace fool2048 {
namespace game {

class HumanGame : public Game {
public:
  HumanGame(board::FullBoard &&full_board, board::Force last_force);
  HumanGame(HumanGame&&) = default;
  ~HumanGame() = default;

protected:
  void BeforeAddNumber() const;
  void BeforeMove() const;

  DISALLOW_COPY_AND_ASSIGN(HumanGame);
};

}
}

#endif /* SRC_GAME_HUMAN_GAME_H_ */
