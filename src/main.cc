/*
 * main.cc
 *
 *  Created on: Mar 17, 2014
 *      Author: chncwang
 */

#include "log_util.h"
#include "game/human_game.h"
#include "game/new_game_builder.h"
#include "board/board.h"

using fool2048::board::Force;
using fool2048::board::FullBoard;
using fool2048::InitLogConfig;
using fool2048::game::HumanGame;
using fool2048::game::NewGameBuilder;

int main() {
  InitLogConfig();
  HumanGame human_game = NewGameBuilder<HumanGame>().Build();
  human_game.Run();
}
