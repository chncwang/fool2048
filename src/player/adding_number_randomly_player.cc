/*
 * default_adding_number_player.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#include "adding_number_randomly_player.h"

#include "board/adding_number_move.h"
#include "board/board.h"
#include "board/def.h"
#include "board/full_board.h"
#include "board/full_board_helper.h"
#include "rand_util.h"

namespace fool2048 {
namespace player {

using board::AddingNumberMove;
using board::Board;
using board::FullBoard;
using board::location::Location;
using board::kBoardLengthSquare;

namespace {

const double kNextNumberIsTwoRate = 0.9;

}

AddingNumberMove
AddingNumberRandomlyPlayer::NextMove(const FullBoard &full_board) const {
  int rand = NextRandomNumber(full_board.EmptyNumberCount());
  Location location;

  int count = 0;
  for (int i = 0; i < kBoardLengthSquare; ++i) {
    if (GetFullBoardNumber(full_board, i) == Board::kEmpty) {
      if (count++ == rand) {
        location.Copy(Board::ToLocation(i));
        break;
      }
    }
  }

  AddingNumberMove::InitialNumber initial_number =
      IsTrueRandomly(kNextNumberIsTwoRate) ?
      AddingNumberMove::InitialNumber::kTwo :
      AddingNumberMove::InitialNumber::kFour;
  return AddingNumberMove(location, initial_number);
}

}
}
