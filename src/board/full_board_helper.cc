/*
 * full_board_helper.cc
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */
#include "board/full_board_helper.h"

#include "board/full_board.h"
#include "board/location/location.h"

namespace fool2048 {
namespace board {

using location::Location;

Number GetFullBoardNumber(const FullBoard &full_board, int index) {
  return full_board.GetNumber(Board::ToLocation(index));
}

Number GetFullBoardNumber(const FullBoard &full_board, int x, int y) {
  return full_board.GetNumber(Location(x, y));
}

}
}
