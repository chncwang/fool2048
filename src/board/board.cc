/*
 * board.cpp
 *
 *  Created on: Mar 17, 2014
 *      Author: chncwang
 */

#include "board/board.h"

#include <string>
#include <utility>

#include "board/board_helper.h"
#include "board/number_util.h"
#include "board/location/location.h"
#include "log_util.h"

namespace fool2048 {
namespace board {

using location::Location;
using log4cplus::Logger;
using std::endl;
using std::function;
using std::ostream;
using std::string;
using std::swap;

namespace {

Logger LOG = Logger::getInstance("fool2048.board.Board");

int NumberWidth(Number number) {
  return number < 10 ? 1 : NumberWidth(number / 10) + 1;
}

int MaxBlankWidth(const Board &board) {
  int max = NumberWidth(GetBoardNumber(board, 0));
  for (int i = 1; i < kBoardLengthSquare; ++i) {
    int width = NumberWidth(GetBoardNumber(board, i));
    if (max < width) {
      max = width;
    }
  }
  return max;
}

string CreateBlankString(int width) {
  string result;
  for (int i = 0; i < width; ++i) {
    result += ' ';
  }
  return result;
}

class IndexLocationTable {

 public:
  IndexLocationTable();

  int index(const Location &location) const {
    return indexes_[location.Y()][location.X()];
  }

  const Location& location(int index) const {
    return locations_.at(index);
  }

 private:
  std::array<Location, kBoardLengthSquare> locations_;
  std::array<std::array<int, kBoardLength>, kBoardLength>
  indexes_;
};

const IndexLocationTable kIndexLocationTable;

IndexLocationTable::IndexLocationTable() {
  Board::ForEachLokation([this](const Location & location) {
    int index = location.Y() * kBoardLength + location.X();
    indexes_.at(location.Y()).at(location.X()) = index;
        locations_.at(index).Copy(location);
  });
}

}

const Number Board::kEmpty = 0;
//const int Board::kBoardLength = 4;
//const int Board::kBoardLengthSquare = Board::kBoardLength * Board::kBoardLength;
//const int Board::kLargeSideXY = Board::kBoardLength - 1;

Board::Board() {
  for (auto &numbers : numbers_) {
    numbers.fill(kEmpty);
  }
}

Number Board::GetNumber(const Location &location) const {
  return numbers_.at(location.Y()).at(location.X());
}

void Board::SetNumber(const Location &location, Number number) {
  Validate(number);
  numbers_.at(location.Y()).at(location.X()) = number;
}

void Board::ForEachLocation(
    const function<void(const Location&, Number*)> &process) {
  Board::ForEachLokation([this, &process](const Location & location) {
    process(location, &numbers_.at(location.Y()).at(location.X()));
  });
}

void Board::ForEachLocation(const std::function<void(const location::Location&,
    Number)> &process) const {
  const_cast<Board *>(this)->ForEachLocation([&process](
      const Location &location, Number * number) {
    process(location, *number);
  });
}

void Board::ForEachLokation(const function<void(const Location&)> &process) {
  for (int y = 0; y < kBoardLength; ++y) {
    for (int x = 0; x < kBoardLength; ++x) {
      process(Location(x, y));
    }
  }
}

int Board::ToIndex(const Location &location) {
  return kIndexLocationTable.index(location);
}

const Location& Board::ToLocation(int index) {
  return kIndexLocationTable.location(index);
}

ostream& operator<<(ostream &out, const Board &board) {
  out << "[" << endl;
  int max_width = MaxBlankWidth(board);

  (const_cast<Board &>(board)).ForEachLocation(
      [&out, max_width](const Location &location, Number * number) {
        out << CreateBlankString(max_width + 1 - NumberWidth(*number)) <<
            *number;
        if (location.X() == kLargeSideXY) {
          out << endl;
        }
      });

  out << "]";
  return out;
}

bool IsEqual(const Board &a, const Board &b) {
  for (int i = 0; i < kBoardLengthSquare; ++i) {
    if (GetBoardNumber(a, i) != GetBoardNumber(b, i)) {
      return false;
    }
  }

  return true;
}

}
}
