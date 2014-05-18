/*
 * full_board.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_FULL_BOARD_H_
#define SRC_BOARD_FULL_BOARD_H_

#include <cassert>

#include <ostream>

#include "board/board.h"
#include "board/def.h"
#include "board/location/orientation.h"
#include "def.h"
#include "force.h"

namespace fool2048 {
namespace board {

class AddingNumberMove;

namespace location {

class Location;

}

class FullBoard {
public:
  static const Number kMaxPossibleNumber = 2048 * 8;

  FullBoard();
  FullBoard(FullBoard &&full_board) = default;
  ~FullBoard() = default;

  void Copy(const FullBoard &full_board);

  const Board &GetBoard() const {
    return board_;
  }

  Number GetNumber(const location::Location &location) const {
    return board_.GetNumber(location);
  }

  int EmptyNumberCount() const {
    return empty_number_count_;
  }

  Force LastForce() const {
    return last_force_;
  }

  void PlayAddingNumberMove(const AddingNumberMove &move);
  void PlayMovingMove(location::Orientation orientation);

  HashKey ZobristHash() const;

  int ResultLevel() const;

  float SquareSum() const;

  int MovingMoveCount() const {
    return moving_move_count_;
  }

protected:

  void SetNumber(const location::Location &location, Number number) {
    board_.SetNumber(location, number);
  }

  void SetEmptyNumberCount(int empty_number_count) {
    empty_number_count_ = empty_number_count;
  }

private:
  void SetNumberAsDouble(const location::Location &location);
  void ValidateBeforeSetDouble(const location::Location &location) const;

  friend std::ostream& operator<<(std::ostream & out,
      const FullBoard &full_board);
  friend bool IsEqual(const FullBoard &a, const FullBoard &b);

  Board board_;
  int empty_number_count_;
  Force last_force_;
  int moving_move_count_;

  DISALLOW_COPY_AND_ASSIGN(FullBoard);
};

}
}

#endif /* SRC_BOARD_FULL_BOARD_H_ */
