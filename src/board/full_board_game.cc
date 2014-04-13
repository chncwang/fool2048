/*
 * full_board_game.cc
 *
 *  Created on: Apr 9, 2014
 *      Author: chncwang
 */

#include "full_board_game.h"

#include "full_board.h"
#include "location_helper.h"

using std::bitset;

bool HasGameEnded(const FullBoard &full_board) {
  if (full_board.EmptyNumberCount() > 0) return false;

  for (int y=0; y<Board::kLargeSideXY; ++y) {
    for (int x=0; x<Board::kLargeSideXY; ++x) {
      Location location(x, y);
      Location right_location = GetLocation(location, Orientation::kRight);
      Location down_location = GetLocation(location, Orientation::kDown);

      Number number = full_board.GetNumber(location);

      if (number == full_board.GetNumber(right_location)
          || number == full_board.GetNumber(down_location)) {
        return false;
      }
    }
  }

  Location corner_location(Board::kLargeSideXY, Board::kLargeSideXY);
  Number corner_num = full_board.GetNumber(corner_location);

  Location corner_left_location =
      GetLocation(corner_location, Orientation::kLeft);
  Number corner_left_num = full_board.GetNumber(corner_left_location);

  Location corner_up_location =
      GetLocation(corner_location, Orientation::kUp);
  Number corner_up_num = full_board.GetNumber(corner_up_location);

  return corner_num != corner_left_num && corner_num != corner_up_num;
}

bitset<4> MovableOrientation(const FullBoard &full_board) {
}
