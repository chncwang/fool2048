/*
 * board.h
 *
 *  Created on: Mar 17, 2014
 *      Author: chncwang
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <cassert>
#include <cstdint>

#include <array>
#include <functional>
#include <ostream>

#include "def.h"

class Board {
public:
  typedef int16_t Number;

  class Location {
  public:
    enum Orientation {
      kRight = 0, kUp = 1, kLeft = 2, kDown = 3
    };

    Location() :
        x_(0), y_(0) {
    }

    Location(int x, int y) {
      x_ = x;
      y_ = y;
    }

    Location(const Location &location) = default;

    Location(Location &&location) = default;

    ~Location() = default;

    Location& operator=(Location &&location) {
      return *this = location;
    }

    Location& operator=(const Location &location);

    int X() const {
      return x_;
    }

    int Y() const {
      return y_;
    }

    static Orientation OppositeOrientation(Orientation orientation) {
      static const Orientation kTable[4] = { Orientation::kLeft,
          Orientation::kDown, Orientation::kRight, Orientation::kUp };
      return kTable[orientation];
    }

  private:
    friend bool operator==(const Location &a, const Location &b) {
      return a.x_ == b.x_ && a.y_ == b.y_;
    }

    friend std::ostream& operator<<(std::ostream& out,
        const Location &location) {
      out << "[x_:" << location.x_ << ", y_:" << location.y_ << "]";
      return out;
    }

    int x_;
    int y_;
  };

  static const int kBoardLength = 4;
  static const int kBoardLengthSquare = kBoardLength * kBoardLength;
  static const int kLargeSideXY = kBoardLength - 1;
  static const Number kEmpty = 0;

  Board();
  ~Board() = default;

  void Copy(const Board &board) {
    numbers_ = board.numbers_;
  }

  Number GetNumber(const Location &location) const {
    return numbers_.at(location.Y()).at(location.X());
  }

  void SetNumber(const Location &location, Number number) {
    numbers_.at(location.Y()).at(location.X()) = number;
  }

  void ForEachLocation(const std::function<
      void(const Board::Location&, Board::Number*)> &process);

  static void ForEachLokation(
      const std::function<void(const Board::Location&)> &process);

  static int ToIndex(const Location &location) {
    return kIndexLocationTable.index(location);
  }

  static const Location& ToLocation(int index) {
    return kIndexLocationTable.location(index);
  }

  DISALLOW_COPY_AND_ASSIGN(Board);

private:
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
    std::array<std::array<int, kBoardLength>, kBoardLength> indexes_;
  };

  static const IndexLocationTable kIndexLocationTable;

  friend std::ostream& operator<<(std::ostream &out, const Board &board);

  std::array<std::array<Number, kBoardLength>, kBoardLength> numbers_;
};

#endif /* BOARD_H_ */
