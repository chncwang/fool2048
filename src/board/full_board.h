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
#include "board/orientation.h"
#include "def.h"

namespace fool2048 {
namespace board {

class AddingNumberMove;
class Location;

class FullBoard {
public:
  static const Number kMaxPossibleNumber = 2048 * 8;

  FullBoard() : empty_number_count_(Board::kBoardLengthSquare) {}

  FullBoard(FullBoard &&full_board) = default;

  ~FullBoard() = default;

  void Copy(const FullBoard &full_board) {
    board_.Copy(full_board.board_);
    empty_number_count_ = full_board.empty_number_count_;
  }

  Number GetNumber(const Location &location) const {
    return board_.GetNumber(location);
  }

  int EmptyNumberCount() const {
    return empty_number_count_;
  }

  void PlayAddingNumberMove(const AddingNumberMove &move);
  void PlayMovingMove(Orientation orientation);

protected:
  void SetNumber(const Location &location, Number number) {
    board_.SetNumber(location, number);
  }

  void SetEmptyNumberCount(int empty_number_count) {
    empty_number_count_ = empty_number_count;
  }

private:
  void SetNumberAsDouble(const Location &location);
  void ValidateBeforeSetDouble(const Location &location) const;

  friend std::ostream& operator<<(std::ostream & out,
      const FullBoard &full_board);
  friend bool IsEqual(const FullBoard &a, const FullBoard &b);

  Board board_;
  int empty_number_count_;

  DISALLOW_COPY_AND_ASSIGN(FullBoard);
};

}
}

#endif /* SRC_BOARD_FULL_BOARD_H_ */
