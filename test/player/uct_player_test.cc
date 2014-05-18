#include "gtest/gtest.h"

#include "uct_player_testable.h"
#include "board/def.h"

namespace fool2048 {
namespace player {

using board::Board;

namespace {

class UctPlayerTest : public ::testing::Test {

};

}

TEST_F(UctPlayerTest, NodeRecord_Constructor) {
  UctPlayerTestable::NodeRecord a;

  ASSERT_EQ(a.VisitedTimes(), 0);
  ASSERT_EQ(a.AverageProfit(), 0.0);
  static const UctPlayerTestable::NodeRecord::Times TIMES = 9999;
  static const float PROFIT = 0.5;
  UctPlayerTestable::NodeRecord b(TIMES, PROFIT);
  ASSERT_EQ(b.VisitedTimes(), TIMES);
  ASSERT_EQ(b.AverageProfit(), PROFIT);
}

}
}