/*
 * full_board.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_H_
#define FULL_BOARD_H_

#include <cassert>

#include <ostream>

#include "board/board.h"
#include "board/orientation.h"
#include "def.h"

class AddingNumberMove;
class Location;

class FullBoard {
public:
  static const Number kMaxPossibleNumber = 2048 * 8;

  FullBoard() : empty_number_count_(Board::kBoardLengthSquare) {}

  ~FullBoard() = default;

  void Copy(FullBoard &full_board) {
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

  DISALLOW_COPY_AND_ASSIGN(FullBoard);

protected:
  Board* GetBoard() {
    return &board_;
  }

  int* EmptyNumberCountPointer() {
    return &empty_number_count_;
  }

private:
  void SetNumberAsDouble(const Location &location);
  void ValidateBeforeSetDouble(const Location &location) const;

  friend std::ostream& operator<<(std::ostream & out,
      const FullBoard &full_board);

  Board board_;
  int empty_number_count_;
};

#endif /* FULL_BOARD_H_ */