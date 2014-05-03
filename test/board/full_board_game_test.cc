/*
 * full_board_game.cc
 *
 *  Created on: Apr 11, 2014
 *      Author: chncwang
 */
#include "board/full_board_game.h"

#include "gtest/gtest.h"

#include "board/full_board_testable.h"
#include "board/full_board_testable_builder.h"
#include "example_boards_test.h"
#include "log_util.h"

namespace fool2048 {
namespace board {

namespace {

class FullBoardGameTest : public ExampleBoardsTest {
};

}

TEST_F(FullBoardGameTest, HasGameEnded) {
  ASSERT_TRUE(HasGameEnded(a_));
  ASSERT_FALSE(HasGameEnded(b_));
  ASSERT_FALSE(HasGameEnded(c_));
  ASSERT_FALSE(HasGameEnded(d_));
  ASSERT_FALSE(HasGameEnded(e_));
  ASSERT_FALSE(HasGameEnded(f_));
  ASSERT_FALSE(HasGameEnded(g_));
  ASSERT_FALSE(HasGameEnded(h_));
}

TEST_F(FullBoardGameTest, IsMovable) {
  ForEachOrientation([&](Orientation orientation) {
      ASSERT_FALSE(IsMovable(a_, orientation));
  });

  ASSERT_TRUE(IsMovable(b_, Orientation::kRight));
  ASSERT_FALSE(IsMovable(b_, Orientation::kUp));
  ASSERT_FALSE(IsMovable(b_, Orientation::kLeft));
  ASSERT_TRUE(IsMovable(b_, Orientation::kDown));

  ForEachOrientation([&](Orientation orientation) {
      ASSERT_TRUE(IsMovable(c_, orientation));
      ASSERT_TRUE(IsMovable(d_, orientation));
      ASSERT_TRUE(IsMovable(f_, orientation));
  });

  ASSERT_TRUE(IsMovable(e_, Orientation::kRight));
  ASSERT_TRUE(IsMovable(e_, Orientation::kUp));
  ASSERT_FALSE(IsMovable(e_, Orientation::kLeft));
  ASSERT_FALSE(IsMovable(e_, Orientation::kDown));

  ASSERT_FALSE(IsMovable(g_, Orientation::kRight));
  ASSERT_TRUE(IsMovable(g_, Orientation::kUp));
  ASSERT_TRUE(IsMovable(g_, Orientation::kLeft));
  ASSERT_FALSE(IsMovable(g_, Orientation::kDown));

  ASSERT_FALSE(IsMovable(h_, Orientation::kRight));
  ASSERT_FALSE(IsMovable(h_, Orientation::kUp));
  ASSERT_TRUE(IsMovable(h_, Orientation::kLeft));
  ASSERT_TRUE(IsMovable(h_, Orientation::kDown));
}

}
}
