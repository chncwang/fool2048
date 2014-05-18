/*
 * human_game.cc
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#include "game/human_game.h"

#include <utility>
#include <iostream>

#include "player/adding_number_randomly_player.h"
#include "player/human_moving_player.h"

namespace fool2048 {
namespace game {

using board::FullBoard;
using board::Force;
using player::AddingNumberRandomlyPlayer;
using player::HumanMovingPlayer;
using std::move;

HumanGame::HumanGame(FullBoard &&full_board) :
    LoggableGame(move(full_board),
    move(Game::AddingNumberPlayerUniquePtr(new AddingNumberRandomlyPlayer)),
    move(Game::MovingPlayerUniquePtr(new HumanMovingPlayer))) { }

}
}
