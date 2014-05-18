/*
 * number_util_test.cc
 *
 *  Created on: May 15, 2014
 *      Author: chncwang
 */
#include "gtest/gtest.h"

#include "log_util.h"
#include "board/number_util.h"

namespace fool2048 {
namespace board {

using log4cplus::Logger;

namespace {

class NumberUtilTest : public ::testing::Test {

 protected:

  void SetUp() {
    InitLogConfig();
  }
};

Logger LOG = Logger::getInstance("fool2048.board.NumberUtilTest");

}

TEST_F(NumberUtilTest, GetLevel) {
  LOG_UTIL_DEBUG(LOG, "assert eq GetLevel(2), 1...");
  ASSERT_EQ(GetLevel(2), 1);
  LOG_UTIL_DEBUG(LOG, "assert eq GetLevel(2), 1...");
  ASSERT_EQ(GetLevel(2), 1);
  ASSERT_EQ(GetLevel(16), 4);
}

}
}
