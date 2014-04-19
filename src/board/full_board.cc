/*
 * full_board.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#include "full_board.h"

#include <cassert>

#include "adding_number_move.h"
#include "board_helper.h"
#include "location.h"
#include "location_helper.h"
#include "log_util.h"

using std::ostream;

void FullBoard::PlayAddingNumberMove(const AddingNumberMove &move) {
  board_.SetNumber(move.GetLocation(), move.GetInitialNumber());
  --empty_number_count_;
}

void FullBoard::PlayMovingMove(Orientation orientation) {
  for (int outter_i = 0; outter_i < Board::kBoardLength; ++outter_i) {
    Location last_number_location;
    bool merge_available = false;
    bool first_number_moved = false;

    for (int inner_i = InnerIndexBegin(orientation);
        inner_i != InnerIndexEnd(orientation);
        inner_i += InnerIndexStep(orientation)) {
      Location current_location = GetLocation(orientation, outter_i, inner_i);
      Number number = board_.GetNumber(current_location);

      LOG_UTIL_DEBUG("current_location " << current_location << " number " <<
          number);

      if (number == Board::kEmpty) continue;

      board_.SetNumber(current_location, Board::kEmpty);

      if (merge_available && number == board_.GetNumber(last_number_location)
          && number != Board::kEmpty) {
        LOG_UTIL_DEBUG("merge condition: " << "last_number_location " <<
            last_number_location << " number " <<
            GetNumber(last_number_location));

        assert(first_number_moved);
        merge_available = false;
        SetNumberAsDouble(last_number_location);
        ++empty_number_count_;
      } else {
        if (!first_number_moved) {
          LOG_UTIL_DEBUG("move first number condition");
          assert(!merge_available);
          first_number_moved = true;
          merge_available = true;
          last_number_location.Copy(
              GetLocation(orientation, outter_i, InnerIndexBegin(orientation)));
        } else {
          LOG_UTIL_DEBUG("move other number condition");
          assert(first_number_moved);
          merge_available = true;
          last_number_location.Copy(GetAdjacentLocation(last_number_location,
              OppositeOrientation(orientation)));
        }
        board_.SetNumber(last_number_location, number);
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
  LOG_UTIL_DEBUG("location " << location << " number " << number);
  assert(number > 0 && number < kMaxPossibleNumber
      && (number & (number - 1)) == 0);
}

ostream& operator<<(ostream & out, const FullBoard &full_board) {
  return out << "[" << full_board.board_ << ", empty_number_count_: "
      << full_board.empty_number_count_ << "]";
}

bool IsEqual(const FullBoard &a, const FullBoard &b) {
  bool result = IsEqual(a.board_, b.board_);
  if (result) {
    assert(a.empty_number_count_ == b.empty_number_count_);
  }
  return result;
}
