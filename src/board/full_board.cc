/*
 * full_board.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#include "full_board.h"

#include "board_helper.h"

using namespace std;

typedef Board::Location::Orientation Orientation;
typedef FullBoard::AddingNumberMove AddingNumberMove;

AddingNumberMove&
AddingNumberMove::operator=(const AddingNumberMove &adding_number_move) {
  if (this != &adding_number_move) {
    location_ = adding_number_move.location_;
    initial_number_ = adding_number_move.initial_number_;
  }
  return *this;
}

void FullBoard::PlayAddingNumberMove(const AddingNumberMove &move) {
  board_.SetNumber(move.GetLocation(), move.GetInitialNumber());
  --empty_number_count_;
}

void FullBoard::PlayMovingMove(Orientation orientation) {
  static const bool is_orientation_to_large_side[4] = {true, false, false, true};

  auto inner_i_begin = [orientation]() {
    return is_orientation_to_large_side[orientation] ? Board::kLargeSideXY : 0;
  };

  auto inner_i_end = [orientation, &inner_i_begin]() {
    return is_orientation_to_large_side[orientation] ? -1 : Board::kBoardLength;
  };

  auto inner_i_step = [orientation, &inner_i_begin]() {
    return inner_i_begin() == 0 ? 1 : -1;
  };

  auto get_location = [orientation](int outter_i, int inner_i) {
    return orientation & 1 == 0 ? Location(inner_i, outter_i) :
    Location(outter_i, inner_i);
  };

  for (int outter_i = 0; outter_i < Board::kBoardLength; ++outter_i) {
    Location last_number_location;
    bool merge_available = false;
    bool first_number_moved = false;

    for (int inner_i = inner_i_begin(); inner_i != inner_i_end(); inner_i +=
        inner_i_step()) {
      board_.SetNumber(get_location(outter_i, inner_i), Board::kEmpty);
      Number number = board_.GetNumber(get_location(outter_i, inner_i));

      if (merge_available && number == board_.GetNumber(last_number_location)) {
        assert(first_number_moved);
        merge_available = false;
        SetNumberAsDouble(last_number_location);
      } else {
        if (!first_number_moved) {
          assert(!merge_available);
          first_number_moved = true;
          merge_available = true;
          last_number_location = Location(inner_i_begin(), outter_i);
        } else {
          assert(first_number_moved);
          merge_available = true;
          last_number_location = GetLocation(last_number_location,
              Location::OppositeOrientation(orientation));
        }
        board_.SetNumber(last_number_location, Board::kEmpty);
      }
    }
  }
}

void FullBoard::SetNumberAsDouble(const Location &location) {
  ValidateBeforeSetDouble(location);
  board_.SetNumber(location, board_.GetNumber(location) << 1);
}

void FullBoard::ValidateBeforeSetDouble(const Location &location) const {
  Number number = board_.GetNumber(location);
  assert(number > 0 && number < kMaxPossibleNumber
      && (number & (number - 1) == 0));
}

ostream& operator<<(ostream & out, const FullBoard &full_board) {
  return out << "[" << full_board.board_ << ", empty_number_count_: "
      << full_board.empty_number_count_ << "]";
}
