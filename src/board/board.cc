/*
 * board.cpp
 *
 *  Created on: Mar 17, 2014
 *      Author: chncwang
 */

#include "board.h"

#include <string>

#include "board_helper.h"

using namespace std;

typedef Board::Location Location;
typedef Board::Number Number;

const Board::IndexLocationTable Board::kIndexLocationTable;

namespace {

int NumberWidth(Number number) {
  return number < 10 ? 1 : NumberWidth(number / 10) + 1;
}

int MaxBlankWidth(const Board &board) {
  int max = NumberWidth(GetBoardNumber(board, 0));
  for (int i = 1; i < Board::kBoardLengthSquare; ++i) {
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

}

Location& Location::operator=(const Location &location) {
  if (this != &location) {
    x_ = location.x_;
    y_ = location.y_;
  }
  return *this;
}

Board::Board() {
  for (int i = 0; i < kBoardLength; ++i) {
    numbers_[i].fill(kEmpty);
  }
}

void Board::ForEachLocation(
    const std::function<void(const Location&, Number*)> &process) {
  for (int y = 0; y < Board::kBoardLength; ++y) {
    for (int x = 0; x < Board::kBoardLength; ++x) {
      Location location(x, y);
      process(location, &numbers_.at(y).at(x));
    }
  }
}

void Board::ForEachLokation(const std::function<void(const Location&)> &process) {
  for (int y = 0; y < Board::kBoardLength; ++y) {
    for (int x = 0; x < Board::kBoardLength; ++x) {
      process(Location(x, y));
    }
  }
}

Board::IndexLocationTable::IndexLocationTable() {
  for (int y = 0; y < kBoardLength; ++y) {
    for (int x = 0; x < kBoardLength; ++x) {
      int index = y * kBoardLength + x;
      indexes_[y][x] = index;
      locations_[index] = Location(x, y);
    }
  }
}

ostream& operator<<(ostream &out, const Board &board) {
  out << "[" << endl;
  int max_width = MaxBlankWidth(board);

  (const_cast<Board &>(board)).ForEachLocation(
      [&out, max_width](const Location &location, Number *number) {
    out << CreateBlankString(max_width + 1 - NumberWidth(*number)) << *number;
  });

  out << "]";
  return out;
}
