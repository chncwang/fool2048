#include "board/location_helper.h"

#include "gtest/gtest.h"

#include "board/location.h"

TEST(LocationHelperTest, GetLocation) {
  static Location location(1, 3);
  ASSERT_TRUE(IsEqual(GetLocation(location, Orientation::kRight),
      Location(2, 3)));
  ASSERT_TRUE(IsEqual(GetLocation(location, Orientation::kUp), Location(1, 2)));
  ASSERT_TRUE(IsEqual(GetLocation(location, Orientation::kLeft),
      Location(0, 3)));
  ASSERT_TRUE(IsEqual(GetLocation(location, Orientation::kDown),
      Location(1, 4)));
}
