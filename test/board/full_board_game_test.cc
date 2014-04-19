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

namespace fool2048 {
namespace board {

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

    FullBoardTestable::Numbers e = {
      2, 4, 2, 0,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 2,
    };
    e_.Init(e);

    FullBoardTestable::Numbers f = {
      0, 4, 2, 2,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 2,
    };
    f_.Init(f);

    FullBoardTestable::Numbers g = {
      0, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 2,
    };
    g_.Init(g);

    FullBoardTestable::Numbers h = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      0, 2, 4, 2,
    };
    h_.Init(h);
  }

  FullBoardTestable a_;
  FullBoardTestable b_;
  FullBoardTestable c_;
  FullBoardTestable d_;
  FullBoardTestable e_;
  FullBoardTestable f_;
  FullBoardTestable g_;
  FullBoardTestable h_;
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
