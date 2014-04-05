/*
 * default_adding_number_player.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#include "default_adding_number_player.h"

#include "board/board.h"
#include "board/full_board.h"
#include "board/full_board_helper.h"
#include "rand_util.h"

namespace {

const double kNextNumberIsTwoRate = 0.9;

}


FullBoard::AddingNumberMove
DefaultAddingNumberPlayer::NextMove(const FullBoard &full_board) const {
  int rand = NextRandomNumber(full_board.EmptyNumberCount());
  Board::Location location;

  int count = 0;
  for (int i = 0; i < Board::kBoardLengthSquare; ++i) {
    if (GetFullBoardNumber(full_board, i) == Board::kEmpty) {
      if (count++ == rand) {
        location = Board::ToLocation(i);
        break;
      }
    }
  }

  FullBoard::InitialNumber initial_number = IsTrueRandomly(kNextNumberIsTwoRate) ?
      FullBoard::InitialNumber::kTwo : FullBoard::InitialNumber::kFour;
  return FullBoard::AddingNumberMove(location, initial_number);
}
