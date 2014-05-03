/* 
 * File:   MonteCarloGame.h
 * Author: chncwang
 *
 * Created on May 2, 2014, 8:48 PM
 */

#ifndef SRC_GAME_MONTE_CARLO_GAME_H_
#define	SRC_GAME_MONTE_CARLO_GAME_H_

#include "def.h"
#include "board/force.h"
#include "game/game.h"

namespace fool2048 {
namespace game {

class MonteCarloGame : public Game {
 public:
  MonteCarloGame(board::FullBoard &&full_board, board::Force force);
  MonteCarloGame(MonteCarloGame&&) = default;
  ~MonteCarloGame() = default;

 private:
  DISALLOW_COPY_AND_ASSIGN(MonteCarloGame);
};

}
}

#endif	/* MONTECARLOGAME_H */

