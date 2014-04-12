/*
 * human_game.h
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#ifndef HUMAN_GAME_H_
#define HUMAN_GAME_H_

#include <game/game.h>

class HumanGame : public Game {
public:
  HumanGame();
  HumanGame(FullBoard &&full_board);
  ~HumanGame() = default;

protected:
  void BeforeAddNumber() const;
  void BeforeMove() const;
};

#endif /* HUMAN_GAME_H_ */
