/*
 * main.cc
 *
 *  Created on: Mar 17, 2014
 *      Author: chncwang
 */

#include "log_util.h"

#include "game/human_game.h"
#include "board/board.h"

using fool2048::InitLogConfig;
using fool2048::game::HumanGame;

int main() {
  InitLogConfig();
  HumanGame human_game;
  human_game.Run();
}
