/*
 * human_moving_player.cc
 *
 *  Created on: Apr 7, 2014
 *      Author: chncwang
 */

#include "player/human_moving_player.h"

#include <iostream>

using std::cin;
using std::cout;

Orientation HumanMovingPlayer::NextMove(const FullBoard &full_board) const {
  cout << "hjkl : ";
  char orientation;
  cin >> orientation;

  switch (orientation) {
    case 'l':
      return Orientation::kRight;
    case 'k':
      return Orientation::kUp;
    case 'h':
      return Orientation::kLeft;
    case 'j':
      return Orientation::kDown;
    default:
      assert(false);
      return -1;
  }
}
