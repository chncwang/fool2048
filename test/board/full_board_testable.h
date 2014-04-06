/*
 * full_board_testable.h
 *
 *  Created on: Apr 4, 2014
 *      Author: chncwang
 */

#ifndef FULL_BOARD_TESTABLE_H_
#define FULL_BOARD_TESTABLE_H_

#include "board/full_board.h"

#include <array>

class FullBoardTestable : public FullBoard {
public:
  typedef std::array<std::array<Number, Board::kBoardLength>,
      Board::kBoardLength> Numbers;

  FullBoardTestable() = default;
  ~FullBoardTestable() = default;

  void Init(const Numbers &numbers);
  void SetNumber(int x, int y, Number number);
};

#endif /* FULL_BOARD_TESTABLE_H_ */
