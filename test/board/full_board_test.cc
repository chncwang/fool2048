/*
 * full_board.cc
 *
 *  Created on: Mar 29, 2014
 *      Author: chncwang
 */

#include "board/location/orientation.h"
#include "board/adding_number_move.h"
#include "board/zobrist_hash_factor.h"
#include "full_board_testable.h"
#include "gtest/gtest.h"
#include "log_util.h"

namespace fool2048 {
namespace board {

using location::Location;
using location::Orientation;
using log4cplus::Logger;

namespace {

Logger LOG = Logger::getInstance("fool2048.board.FullBoardTest");

FullBoardTestable::Numbers CreateNumbers() {
  FullBoardTestable::Numbers numbers = {
    0, 2, 8, 8,
    2, 4, 8, 16,
    0, 4, 32, 32,
    2, 16, 32, 64
  };
  return numbers;
}

class FullBoardTest : public testing::Test {

 protected:

  virtual void SetUp() {
    InitLogConfig();

    full_board_.Init(CreateNumbers());
  }

  FullBoardTestable full_board_;
};

}

TEST_F(FullBoardTest, Copy) {
  FullBoardTestable full_board;
  full_board.Copy(full_board_);
  ASSERT_TRUE(IsEqual(full_board_, full_board));
}

TEST_F(FullBoardTest, PlayMovingMove) {
  FullBoardTestable expected_board;

  FullBoard to_right_board;
  to_right_board.Copy(full_board_);

  to_right_board.PlayMovingMove(Orientation::kRight);
  LOG_UTIL_DEBUG(LOG, "to_right_board " << to_right_board);

  FullBoardTestable::Numbers to_right_numbers = {
    0, 0, 2, 16,
    2, 4, 8, 16,
    0, 0, 4, 64,
    2, 16, 32, 64
  };

  expected_board.Init(to_right_numbers);
  ASSERT_TRUE(IsEqual(to_right_board, expected_board));

  FullBoard to_up_board;
  to_up_board.Copy(full_board_);

  to_up_board.PlayMovingMove(Orientation::kUp);
  LOG_UTIL_DEBUG(LOG, "to_up_board " << to_up_board);

  FullBoardTestable::Numbers to_up_numbers = {
    4, 2, 16, 8,
    0, 8, 64, 16,
    0, 16, 0, 32,
    0, 0, 0, 64
  };

  expected_board.Init(to_up_numbers);
  ASSERT_TRUE(IsEqual(to_up_board, expected_board));

  FullBoard to_left_board;
  to_left_board.Copy(full_board_);

  to_left_board.PlayMovingMove(Orientation::kLeft);
  LOG_UTIL_DEBUG(LOG, "to_left_board " << to_left_board);

  FullBoardTestable::Numbers to_left_numbers = {
    2, 16, 0, 0,
    2, 4, 8, 16,
    4, 64, 0, 0,
    2, 16, 32, 64
  };

  expected_board.Init(to_left_numbers);
  ASSERT_TRUE(IsEqual(to_left_board, expected_board));

  FullBoard to_down_board;
  to_down_board.Copy(full_board_);

  to_down_board.PlayMovingMove(Orientation::kDown);
  LOG_UTIL_DEBUG(LOG, "to_down_board " << to_down_board);

  FullBoardTestable::Numbers to_down_numbers = {
    0, 0, 0, 8,
    0, 2, 0, 16,
    0, 8, 16, 32,
    4, 16, 64, 64
  };

  expected_board.Init(to_down_numbers);
  ASSERT_TRUE(IsEqual(to_down_board, expected_board));
}

TEST_F(FullBoardTest, ZobristHash) {
  FullBoard full_board;
  HashKey a = full_board.ZobristHash();
  LOG_UTIL_DEBUG(LOG, "full_board " << full_board << " a " << a);
  HashKey b = full_board.ZobristHash();
  ASSERT_EQ(a, b);

  Location location_c = Location(2, 2);
  Number number_c = 2;
  full_board.PlayAddingNumberMove(AddingNumberMove(location_c,
      static_cast<AddingNumberMove::InitialNumber>(number_c)));
  HashKey c = full_board.ZobristHash();
  LOG_UTIL_DEBUG(LOG, "full_board " << full_board << " c " << c);

  ZobristHashFactor * zobrist_hash_factor = ZobristHashFactor::GetInstance();
  HashKey adding_number_force_factor =
      zobrist_hash_factor->GetForceFactor(Force::kAddingNumber);
  HashKey moving_force_factor =
      zobrist_hash_factor->GetForceFactor(Force::kMoving);
  HashKey before_factor = zobrist_hash_factor->GetLocationFactor(location_c,
      Board::kEmpty);
  HashKey after_factor = zobrist_hash_factor->GetLocationFactor(location_c,
      number_c);
  ASSERT_EQ(c, a ^ adding_number_force_factor ^ moving_force_factor ^
      before_factor ^ after_factor);
}

TEST_F(FullBoardTest, OperatorDoubleLeftArrow) {
  LOG_UTIL_DEBUG(LOG, "full_board" << full_board_);
}

TEST_F(FullBoardTest, IsEqual) {
  FullBoardTestable full_board;
  ASSERT_FALSE(IsEqual(full_board, full_board_));
  full_board.Init(CreateNumbers());
  ASSERT_TRUE(IsEqual(full_board, full_board_));
}

}
}
