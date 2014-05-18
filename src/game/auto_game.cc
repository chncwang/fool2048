/*
 * auto_game.cc
 *
 *  Created on: May 17, 2014
 *      Author: chncwang
 */

#include "game/auto_game.h"

#include <utility>

#include "player/adding_number_randomly_player.h"
#include "player/uct_player.h"

namespace fool2048 {
namespace game {

using board::FullBoard;
using player::AddingNumberRandomlyPlayer;
using player::UctPlayer;
using std::move;

AutoGame::AutoGame(FullBoard&& full_board) : LoggableGame(move(full_board),
    move(Game::AddingNumberPlayerUniquePtr(new AddingNumberRandomlyPlayer)),
    move(Game::MovingPlayerUniquePtr(new UctPlayer))) { }

} /* namespace player */
} /* namespace fool2048 */
