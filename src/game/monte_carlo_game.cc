/* 
 * File:   MonteCarloGame.cc
 * Author: chncwang
 * 
 * Created on May 2, 2014, 8:48 PM
 */

#include "game/monte_carlo_game.h"

#include <utility>

#include "board/full_board.h"
#include "human_game.h"
#include "player/adding_number_randomly_player.h"
#include "player/moving_randomly_player.h"

namespace fool2048 {
namespace game {

using board::FullBoard;
using board::Force;
using player::AddingNumberRandomlyPlayer;
using player::MovingRandomlyPlayer;
using std::move;

MonteCarloGame::MonteCarloGame(FullBoard &&full_board, Force last_force) :
    Game(move(full_board),
    last_force,
    std::move(Game::AddingNumberPlayerUniquePtr(
        new AddingNumberRandomlyPlayer)),
    std::move(Game::MovingPlayerUniquePtr(new MovingRandomlyPlayer))) {}

}
}