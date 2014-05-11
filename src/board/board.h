/*
 * board.h
 *
 *  Created on: Mar 17, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_BOARD_H_
#define SRC_BOARD_BOARD_H_

#include <cassert>

#include <array>
#include <functional>
#include <ostream>

#include "../def.h"
#include "board/def.h"
#include "location/location.h"

namespace fool2048 {
namespace board {

namespace location {

class Location;

}

class Board {
public:
  static const int kBoardLength = 4;
  static const int kBoardLengthSquare = kBoardLength * kBoardLength;
  static const int kLargeSideXY = kBoardLength - 1;
  static const Number kEmpty;

  Board();

  Board(Board &&board) = default;

  ~Board() = default;

  void Copy(const Board &board) {
    numbers_ = board.numbers_;
  }

  Number GetNumber(const location::Location &location) const;

  void SetNumber(const location::Location &location, Number number);

  void ForEachLocation(const std::function<
      void(const location::Location&, Number*)> &process);
  void ForEachLocation(const std::function<void(const location::Location&,
      Number)> &process) const;

  static void ForEachLokation(
      const std::function<void(const location::Location&)> &process);

  static int ToIndex(const location::Location &location);

  static const location::Location& ToLocation(int index);

private:
  typedef std::ostream ostream;

  class IndexLocationTable;

  friend ostream& operator<<(ostream &out, const Board &board);
  friend bool IsEqual(const Board &a, const Board &b);

  std::array<std::array<Number, kBoardLength>, kBoardLength> numbers_;

  DISALLOW_COPY_AND_ASSIGN(Board);
};

}
}

#endif /* SRC_BOARD_BOARD_H_ */
