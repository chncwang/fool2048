/*
 * full_board_game.cc
 *
 *  Created on: Apr 11, 2014
 *      Author: chncwang
 */
#include "board/full_board_game.h"

#include "gtest/gtest.h"

#include "full_board_testable.h"

TEST(FullBoardGameTest, HasGameEnded) {
  FullBoardTestable full_board;

  FullBoardTestable::Numbers a = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 2
  };
  full_board.Init(a);
  ASSERT_TRUE(HasGameEnded(full_board));

  FullBoardTestable::Numbers b = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 0,
  };
  full_board.Init(b);
  ASSERT_FALSE(HasGameEnded(full_board));

  FullBoardTestable::Numbers c = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 4, 4,
  };
  full_board.Init(c);
  ASSERT_FALSE(HasGameEnded(full_board));

  FullBoardTestable::Numbers d = {
      2, 4, 2, 4,
      4, 2, 4, 2,
      2, 4, 2, 4,
      4, 2, 2, 2,
  };
  full_board.Init(d);
  ASSERT_FALSE(HasGameEnded(full_board));
}
