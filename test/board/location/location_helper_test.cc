#include "board/location/location_helper.h"

#include "gtest/gtest.h"

#include "board/location/location.h"

namespace fool2048 {
namespace board {
namespace location {

TEST(LocationHelperTest, GetAdjacentLocation) {
  static Location location(1, 3);
  ASSERT_TRUE(IsEqual(GetAdjacentLocation(location, Orientation::kRight),
      Location(2, 3)));
  ASSERT_TRUE(IsEqual(GetAdjacentLocation(location, Orientation::kUp), Location(1, 2)));
  ASSERT_TRUE(IsEqual(GetAdjacentLocation(location, Orientation::kLeft),
      Location(0, 3)));
  ASSERT_TRUE(IsEqual(GetAdjacentLocation(location, Orientation::kDown),
      Location(1, 4)));
}

}
}
}