/*
 * full_board_game.cc
 *
 *  Created on: Apr 11, 2014
 *      Author: chncwang
 */
#include "board/full_board_game.h"

#include "gtest/gtest.h"

#include "full_board_testable.h"
#include "log_util.h"

namespace {

class FullBoardGameTest : public testing::Test {
protected:
  virtual void SetUp() {
    InitLogConfig();

    FullBoardTestable::Numbers a = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 2
    };
    a_.Init(a);

    FullBoardTestable::Numbers b = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 0,
    };
    b_.Init(b);

    FullBoardTestable::Numbers c = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 4,
    };
    c_.Init(c);

    FullBoardTestable::Numbers d = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 2, 2,
    };
    d_.Init(d);
  }

  FullBoardTestable a_;
  FullBoardTestable b_;
  FullBoardTestable c_;
  FullBoardTestable d_;
};

}

TEST_F(FullBoardGameTest, HasGameEnded) {
  ASSERT_TRUE(HasGameEnded(a_));
  ASSERT_FALSE(HasGameEnded(b_));
  ASSERT_FALSE(HasGameEnded(c_));
  ASSERT_FALSE(HasGameEnded(d_));
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
  });
}
