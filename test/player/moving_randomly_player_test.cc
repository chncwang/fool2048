/*
 * moving_randomly_player.cc
 *
 *  Created on: Apr 20, 2014
 *      Author: chncwang
 */

#include "gtest/gtest.h"

#include "example_boards_test.h"
#include "board/full_board.h"
#include "player/moving_randomly_player.h"
#include "player/moving_player.h"

namespace fool2048 {
namespace player {

using board::FullBoard;
using board::Orientation;
using log4cplus::Logger;

namespace {

Logger LOG = Logger::getInstance("fool2048.player.MovingRandomlyPlayerTest");

class MovingRandomlyPlayerTest : public ExampleBoardsTest {

};

const int TIME = 10;

}

TEST_F(MovingRandomlyPlayerTest, NextMove) {
  MovingRandomlyPlayer player;

  auto test_board = [&](const FullBoard &full_board) {
    for (int i = 0; i < TIME; ++i) {
      Orientation orientation = player.NextMove(full_board);
      LOG_UTIL_DEBUG("orientation " << orientation);
    }
  };


  test_board(b_);
  test_board(c_);
  test_board(d_);
}

}
}
