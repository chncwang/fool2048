/*
 * monte_carlo_game_test.cc
 *
 *  Created on: May 2, 2014
 *      Author: chncwang
 */

#include "monte_carlo_game_testable.h"

#include "game/new_game_builder.h"
#include "log_util.h"

#include "gtest/gtest.h"

namespace fool2048 {
namespace game {

using game::MonteCarloGameTestable;

namespace {

class MonteCarloGameTest : public ::testing::Test {

 protected:

  virtual void SetUp() {
    InitLogConfig();
  }
};

}

TEST_F(MonteCarloGameTest, Run) {
  MonteCarloGameTestable game =
      NewGameBuilder<MonteCarloGameTestable>().Build();
  game.Run();
}

}
}
