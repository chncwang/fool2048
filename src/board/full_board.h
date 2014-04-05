/*
 * full_board.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_H_
#define FULL_BOARD_H_

#include "board.h"

#include <cassert>

#include <ostream>

class FullBoard {
public:
  typedef Board::Location Location;
  typedef Board::Number Number;

  enum InitialNumber {
    kTwo = 2, kFour = 4
  };

  class AddingNumberMove {
  public:
    AddingNumberMove(const Location &location, InitialNumber initial_number) :
        location_(location), initial_number_(initial_number) {
    }

    AddingNumberMove(AddingNumberMove &&adding_number_move) = default;

    AddingNumberMove& operator=(const AddingNumberMove &adding_number_move);

    AddingNumberMove& operator=(AddingNumberMove &&adding_number_move) {
      return *this = adding_number_move;
    }

    const Location& GetLocation() const {
      return location_;
    }

    InitialNumber GetInitialNumber() const {
      return initial_number_;
    }

  private:
    friend std::ostream& operator<<(std::ostream &out,
        const AddingNumberMove &adding_number_move) {
      out << "[location_:" << adding_number_move.location_
          << ", initial_number_:" << adding_number_move.initial_number_ << "]";
      return out;
    }

    Location location_;
    InitialNumber initial_number_;
  };

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
  void PlayMovingMove(Location::Orientation orientation);

  DISALLOW_COPY_AND_ASSIGN(FullBoard);

protected:
  Board* GetBoard() {
    return &board_;
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
