/*
 * game.h
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <ostream>

#include "def.h"
#include "board/full_board.h"
#include "board/force.h"
#include "player/adding_number_player.h"
#include "player/moving_player.h"

class Game {
public:
  typedef std::unique_ptr<AddingNumberPlayer>
  AddingNumberPlayerUniquePtr;
  typedef std::unique_ptr<MovingPlayer> MovingPlayerUniquePtr;

  virtual ~Game();

  void Run();

protected:
  Game(FullBoard &&full_board,
      AddingNumberPlayerUniquePtr &&adding_number_player,
      MovingPlayerUniquePtr &&moving_player);

  virtual void BeforeAddNumber() const {}
  virtual void BeforeMove() const {}

  void FullBoardToStream(std::ostream &out) const {
    out << full_board_;
  }

private:
  FullBoard full_board_;
  AddingNumberPlayerUniquePtr adding_number_player_unique_ptr_;
  MovingPlayerUniquePtr moving_player_unique_ptr_;
  Force last_force_;

  DISALLOW_COPY_AND_ASSIGN(Game);
};

#endif /* GAME_H_ */
