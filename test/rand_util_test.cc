/*
 * rand_util_test.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */
#include "rand_util.h"

#include "gtest/gtest.h"
#include "log_util.h"

namespace fool2048 {

using log4cplus::Logger;

namespace {

class RandUtilTest : public testing::Test {
protected:
  virtual void SetUp() {
    InitLogConfig();
  }
};

const int TIME = 100;

const Logger LOG = Logger::getInstance("fool2048.RandUtilTest");

}


TEST_F(RandUtilTest, NextRandomNumber) {
  for (int i=0; i<100; ++i) {
    int random_num = NextRandomNumber(100);
    LOG_UTIL_DEBUG(LOG, "random_num " << random_num);
    ASSERT_TRUE(random_num >= 0 && random_num < 100);
  }

  for (int i=0; i<100; ++i) {
    int random_num = NextRandomNumber(1);
    LOG_UTIL_DEBUG(LOG, "random_num - should be 0 " << random_num);
    ASSERT_EQ(random_num, 0);
  }
}

TEST_F(RandUtilTest, IsTrueRandomly) {
  for (int i=0; i<100; ++i) {
    bool result = IsTrueRandomly(0.1);
    LOG_UTIL_DEBUG(LOG, "result " << result);
  }
}

}
