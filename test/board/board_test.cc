#include "board/board.h"

#include <ostream>
#include <utility>

#include "gtest/gtest.h"
#include "board/board_helper.h"
#include "board/location.h"
#include "log_util.h"

using std::move;

namespace {

class BoardTest : public testing::Test {
protected:
  virtual void SetUp() {
    InitLogConfig();
  }
};

}

TEST_F(BoardTest, Constructor) {
  Board board;
  Number empty_number = Board::kEmpty;

  board.ForEachLocation([empty_number](const Location &location,
      Number *number) {
    ASSERT_EQ(*number, empty_number);
  });
}

TEST_F(BoardTest, Copy) {
  Board board;

  board.ForEachLocation([](const Location &location,
      Number *number) {
    *number = 2 << (location.X() + location.Y());
  });

  Board copied_board;
  copied_board.Copy(board);

  copied_board.ForEachLocation([&board](const Location &location,
      Number *number) {
    ASSERT_EQ(*number, board.GetNumber(location));
  });

  Board move_copied_board(move(board));
  move_copied_board.ForEachLocation([&copied_board](const Location &location,
      Number *number) {
    ASSERT_EQ(*number, copied_board.GetNumber(location));
  });
}

TEST_F(BoardTest, SetNumber) {
  Board board;
  Location location_2_3(2, 3);
  board.SetNumber(location_2_3, 1024);
  ASSERT_EQ(board.GetNumber(location_2_3), 1024);
  board.SetNumber(location_2_3, 2048);
  ASSERT_EQ(board.GetNumber(location_2_3), 2048);
}

TEST_F(BoardTest, ForEachLocation) {
  static const int kSetNumber = 1024;
  Board board;

  for (int y = 0; y < Board::kBoardLength; ++y) {
    for (int x = 0; x < Board::kBoardLength; ++x) {
      SetBoardNumber(&board, x, y, kSetNumber);
    }
  }

  board.ForEachLocation([](const Location &location, Number *number) {
    *number <<= 1;
  });

  static const int kDoubleSetNumber = kSetNumber << 1;

  for (int y = 0; y < Board::kBoardLength; ++y) {
    for (int x = 0; x < Board::kBoardLength; ++x) {
      ASSERT_EQ(GetBoardNumber(board, x, y), kDoubleSetNumber);
    }
  }
}

TEST_F(BoardTest, ToIndex) {
  ASSERT_EQ(Board::ToIndex(Location(0, 0)), 0);
  ASSERT_EQ(Board::ToIndex(Location(3, 3)), 15);
  ASSERT_EQ(Board::ToIndex(Location(0, 3)), 12);
  ASSERT_EQ(Board::ToIndex(Location(3, 0)), 3);
  ASSERT_EQ(Board::ToIndex(Location(1, 2)), 9);
  ASSERT_EQ(Board::ToIndex(Location(0, 1)), 4);
  ASSERT_EQ(Board::ToIndex(Location(3, 2)), 11);
  ASSERT_EQ(Board::ToIndex(Location(2, 0)), 2);
  ASSERT_EQ(Board::ToIndex(Location(1, 3)), 13);
}

TEST_F(BoardTest, ToLocation) {
  ASSERT_TRUE(IsEqual(Board::ToLocation(0), Location(0, 0)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(15), Location(3, 3)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(12), Location(0, 3)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(3), Location(3, 0)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(9), Location(1, 2)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(4), Location(0, 1)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(11), Location(3, 2)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(2), Location(2, 0)));
  ASSERT_TRUE(IsEqual(Board::ToLocation(13), Location(1, 3)));
}

TEST_F(BoardTest, OperatorDoubleLeftArrow) {
  Board board;
  board.SetNumber(Location(2, 2), 2048);
  LOG_UTIL_DEBUG("board" << board);
}

TEST_F(BoardTest, IsEqual) {
  Board board_a, board_b;
  ASSERT_TRUE(IsEqual(board_a, board_b));

  Location location_a(0, 0), location_b(2, 1), location_c(1, 3);
  Number num_a(4), num_b(2048), num_c(4096);

  board_a.SetNumber(location_a, num_a);
  ASSERT_FALSE(IsEqual(board_a, board_b));
  board_a.SetNumber(location_b, num_b);
  ASSERT_FALSE(IsEqual(board_a, board_b));
  board_a.SetNumber(location_c, num_c);
  ASSERT_FALSE(IsEqual(board_a, board_b));

  board_b.SetNumber(location_a, num_a);
  ASSERT_FALSE(IsEqual(board_a, board_b));
  board_b.SetNumber(location_b, num_b);
  ASSERT_FALSE(IsEqual(board_a, board_b));
  board_b.SetNumber(location_c, num_c);
  ASSERT_TRUE(IsEqual(board_a, board_b));
}
