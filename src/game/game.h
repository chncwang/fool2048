/*
 * game.h
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#ifndef SRC_GAME_GAME_H_
#define SRC_GAME_GAME_H_

#include <memory>
#include <ostream>

#include "def.h"
#include "board/full_board.h"
#include "board/force.h"
#include "player/adding_number_player.h"
#include "player/moving_player.h"

namespace fool2048 {
namespace game {

class Game {
public:
  typedef std::unique_ptr<player::AddingNumberPlayer>
  AddingNumberPlayerUniquePtr;
  typedef std::unique_ptr<player::MovingPlayer> MovingPlayerUniquePtr;

  Game(Game &&game) = default;

  virtual ~Game();

  const board::FullBoard& GetFullBoard() const {
      return full_board_;
  }

  void Run();

protected:
  Game(board::FullBoard &&full_board,
       board::Force last_force,
       AddingNumberPlayerUniquePtr &&adding_number_player,
       MovingPlayerUniquePtr &&moving_player);

  virtual void BeforeAddNumber() const {}
  virtual void BeforeMove() const {}

private:
  board::FullBoard full_board_;
  AddingNumberPlayerUniquePtr adding_number_player_unique_ptr_;
  MovingPlayerUniquePtr moving_player_unique_ptr_;
  board::Force last_force_;

  DISALLOW_COPY_AND_ASSIGN(Game);
};

}
}

#endif /* SRC_GAME_GAME_H_ */
