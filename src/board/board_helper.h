/*
 * board_helper.h
 *
 *  Created on: Mar 29, 2014
 *      Author: chncwang
 */

#ifndef BOARD_HELPER_H_
#define BOARD_HELPER_H_

#include "board/board.h"

inline Board::Location GetLocation(const Board::Location &location,
    Board::Location::Orientation orientation) {
  static const int kOrientationUnit[4][2] = { 1, 0, 0, -1, -1, 0, 0, 1 };
  return Board::Location(location.X() + kOrientationUnit[orientation][0],
      location.Y() + kOrientationUnit[orientation][1]);
}

inline Board::Number GetBoardNumber(const Board &board, int index) {
  return board.GetNumber(Board::ToLocation(index));
}

inline Board::Number GetBoardNumber(const Board &board, int x, int y) {
  return board.GetNumber(Board::Location(x, y));
}

inline void SetBoardNumber(Board *board, int x, int y, Board::Number number) {
  board->SetNumber(Board::Location(x, y), number);
}

#endif /* BOARD_HELPER_H_ */
