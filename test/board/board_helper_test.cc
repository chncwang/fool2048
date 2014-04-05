#include "board/board_helper.h"

#include "gtest/gtest.h"

typedef Board::Location Location;
typedef Location::Orientation Orientation;

TEST(BoardHelperTest, GetLocation) {
  static Board::Location location(1, 3);
  ASSERT_EQ(GetLocation(location, Orientation::kRight), Location(2, 3));
  ASSERT_EQ(GetLocation(location, Orientation::kUp), Location(1, 2));
  ASSERT_EQ(GetLocation(location, Orientation::kLeft), Location(0, 3));
  ASSERT_EQ(GetLocation(location, Orientation::kDown), Location(1, 4));
}
