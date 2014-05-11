/*
 * new_game_builder.h
 *
 *  Created on: May 3, 2014
 *      Author: chncwang
 */

#ifndef SRC_GAME_NEW_GAME_BUILDER_H_
#define SRC_GAME_NEW_GAME_BUILDER_H_

#include <utility>

#include "board/force.h"
#include "board/full_board.h"
#include "board/adding_number_move.h"
#include "game/game.h"
#include "player/adding_number_randomly_player.h"

namespace fool2048 {
namespace game {

template<class G>
class NewGameBuilder {
public:
  NewGameBuilder();
  ~NewGameBuilder() = default;

  NewGameBuilder& SetLastForce(board::Force last_force);

  NewGameBuilder& SetAddingNumberPlayer(game::Game::AddingNumberPlayerUniquePtr
      &&initialization_player);

  G Build() const;

private:
  game::Game::AddingNumberPlayerUniquePtr initialization_player_;
};

template<class G>
NewGameBuilder<G>::NewGameBuilder() :
    initialization_player_(game::Game::AddingNumberPlayerUniquePtr(
    new player::AddingNumberRandomlyPlayer)) {
}

template<class G>
NewGameBuilder<G>& NewGameBuilder<G>::SetAddingNumberPlayer(
    game::Game::AddingNumberPlayerUniquePtr &&initialization_player) {
  initialization_player_ = std::move(initialization_player);
  return *this;
}

template<class G>
G NewGameBuilder<G>::Build() const {
  board::FullBoard full_board;

  for (int i = 0; i < 2; ++i) {
    board::AddingNumberMove move = initialization_player_->NextMove(full_board);
    full_board.PlayAddingNumberMove(move);
  }

  return G(std::move(full_board));
}

} /* namespace game */
} /* namespace fool2048 */
#endif /* SRC_GAME_NEW_GAME_BUILDER_H_ */
