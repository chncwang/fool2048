/*
 * monte_carlo_game_testable.h
 *
 *  Created on: May 2, 2014
 *      Author: chncwang
 */

#ifndef TEST_GAME_MONTE_CARLO_GAME_TESTABLE_H_
#define TEST_GAME_MONTE_CARLO_GAME_TESTABLE_H_

#include "game/monte_carlo_game.h"

namespace fool2048 {
namespace game {

class MonteCarloGameTestable : public MonteCarloGame {
public:
  MonteCarloGameTestable(board::FullBoard &&full_board);
  MonteCarloGameTestable(MonteCarloGameTestable&&) = default;
  ~MonteCarloGameTestable() = default;

protected:
  void BeforeAddNumber() const;
  void BeforeMove() const;

private:
  DISALLOW_COPY_AND_ASSIGN(MonteCarloGameTestable);
};

} /* namespace game */
} /* namespace fool2048 */

#endif /* MONTE_CARLO_GAME_TESTABLE_H_ */
