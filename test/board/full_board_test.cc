/*
 * full_board.cc
 *
 *  Created on: Mar 29, 2014
 *      Author: chncwang
 */

#include "board/orientation.h"
#include "full_board_testable.h"
#include "gtest/gtest.h"
#include "log_util.h"

using namespace std;

namespace {

class FullBoardTest : public testing::Test {
protected:
  virtual void SetUp() {
    InitLogConfig();

    FullBoardTestable::Numbers numbers = {0,  2,  8,  8,
                                          2,  4,  8, 16,
                                          0,  4, 32, 32,
                                          2, 16, 32, 64};
    full_board_.Init(numbers);
  }

  FullBoardTestable full_board_;
};

}

TEST_F(FullBoardTest, OperatorDoubleLeftArrow) {
  LOG_UTIL_DEBUG("full_board" << full_board_);
}

TEST_F(FullBoardTest, PlayMovingMove) {
  FullBoard to_right_board;
  to_right_board.Copy(full_board_);

  to_right_board.PlayMovingMove(Orientation::kRight);
  LOG_UTIL_DEBUG("to_right_board " << to_right_board);
}
