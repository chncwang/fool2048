/*

 * board_helper.cc
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */
#include "board/board.h"
#include "board/board_helper.h"
#include "board/location/location.h"

namespace fool2048 {
namespace board {

using location::Location;
using location::Orientation;

namespace {
static const bool is_orientation_to_large_side[4] = {
  true, false, false, true
};
}

Number GetBoardNumber(const Board &board, int index) {
  return board.GetNumber(Board::ToLocation(index));
}

Number GetBoardNumber(const Board &board, int x, int y) {
  return board.GetNumber(Location(x, y));
}

void SetBoardNumber(Board *board, int x, int y, Number number) {
  board->SetNumber(Location(x, y), number);
}

int InnerIndexBegin(Orientation orientation) {
  return is_orientation_to_large_side[orientation] ? kLargeSideXY : 0;
}

int InnerIndexEnd(Orientation orientation) {
  return is_orientation_to_large_side[orientation] ? -1 : kBoardLength;
}

int InnerIndexStep(Orientation orientation) {
  return InnerIndexBegin(orientation) == 0 ? 1 : -1;
}

Location
GetLocation(Orientation orientation, int outter_index, int inner_index) {
  return (orientation & 1) == 0 ? Location(inner_index, outter_index) :
      Location(outter_index, inner_index);
}

}
}
