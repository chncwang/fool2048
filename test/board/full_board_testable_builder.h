#ifndef TEST_BOARD_FULL_BOARD_TESTABLE_BUILDER_
#define TEST_BOARD_FULL_BOARD_TESTABLE_BUILDER_

#include <utility>

#include "board/full_board_testable.h"

namespace fool2048 {
namespace board {

using std::move;

namespace {

FullBoardTestable Build(const FullBoardTestable::Numbers &numbers) {
  FullBoardTestable full_board;
  full_board.Init(numbers);
  return move(full_board);
}

}

inline FullBoardTestable BuildA() {
  static FullBoardTestable::Numbers numbers = {
    2, 4, 2, 4,
    4, 2, 4, 2,
    2, 4, 2, 4,
    4, 2, 4, 2
  };

  return Build(numbers);
}

inline FullBoardTestable BuildB() {
  static FullBoardTestable::Numbers numbers = {
    2, 4, 2, 4,
    4, 2, 4, 2,
    2, 4, 2, 4,
    4, 2, 4, 0,
  };

  return Build(numbers);
}

inline FullBoardTestable BuildC() {
  static FullBoardTestable::Numbers numbers = {
    2, 4, 2, 4,
    4, 2, 4, 2,
    2, 4, 2, 4,
    4, 2, 4, 4,
  };

  return Build(numbers);
}

inline FullBoardTestable BuildD() {
  static FullBoardTestable::Numbers numbers = {
    2, 4, 2, 4,
    4, 2, 4, 2,
    2, 4, 2, 4,
    4, 2, 2, 2,
  };

  return Build(numbers);
}

inline FullBoardTestable BuildE() {
  static FullBoardTestable::Numbers numbers = {
    2, 4, 2, 0,
    4, 2, 4, 2,
    2, 4, 2, 4,
    4, 2, 4, 2,
  };

  return Build(numbers);
}

inline FullBoardTestable BuildF() {
  static FullBoardTestable::Numbers numbers = {
    0, 4, 2, 2,
    4, 2, 4, 2,
    2, 4, 2, 4,
    4, 2, 4, 2,
  };

  return Build(numbers);
}

inline FullBoardTestable BuildG() {
  static FullBoardTestable::Numbers numbers = {
    0, 4, 2, 4,
    4, 2, 4, 2,
    2, 4, 2, 4,
    4, 2, 4, 2,
  };

  return Build(numbers);
}

inline FullBoardTestable BuildH() {
  static FullBoardTestable::Numbers numbers = {
    2, 4, 2, 4,
    4, 2, 4, 2,
    2, 4, 2, 4,
    0, 2, 4, 2,
  };

  return Build(numbers);
}

}
}

#endif
