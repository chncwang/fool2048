#include "full_board_testable.h"

void FullBoardTestable::Init(const FullBoardTestable::Numbers &numbers) {
  for (int y = 0; y < Board::kBoardLength; ++y) {
    for (int x = 0; x < Board::kBoardLength; ++x) {
      auto number = numbers.at(y).at(x);
      SetNumber(x, y, number == 0 ? Board::kEmpty : number);
    }
  }
}
