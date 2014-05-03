/*
 * basic_board_test.h
 *
 *  Created on: Apr 20, 2014
 *      Author: chncwang
 */

#ifndef TEST_EXAMPLE_BOARDS_TEST_H_
#define TEST_EXAMPLE_BOARDS_TEST_H_

#include "gtest/gtest.h"

#include "board/full_board_testable.h"
#include "board/full_board_testable_builder.h"
#include "log_util.h"

namespace fool2048 {

class ExampleBoardsTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    InitLogConfig();

    a_.Copy(board::BuildA());
    b_.Copy(board::BuildB());
    c_.Copy(board::BuildC());
    d_.Copy(board::BuildD());
    e_.Copy(board::BuildE());
    f_.Copy(board::BuildF());
    g_.Copy(board::BuildG());
    h_.Copy(board::BuildH());
  }

  board::FullBoardTestable a_;
  board::FullBoardTestable b_;
  board::FullBoardTestable c_;
  board::FullBoardTestable d_;
  board::FullBoardTestable e_;
  board::FullBoardTestable f_;
  board::FullBoardTestable g_;
  board::FullBoardTestable h_;
};

}

#endif /* TEST_EXAMPLE_BOARDS_TEST_H_ */
