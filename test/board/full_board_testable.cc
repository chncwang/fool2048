#include "full_board_testable.h"

#include "board/location/location.h"

namespace fool2048 {
namespace board {

using location::Location;

void FullBoardTestable::Init(const Numbers &numbers) {
  int empty_number_count = 0;

  Board::ForEachLokation([this, &numbers, &empty_number_count](
      const Location &location) {
    Number number = numbers.at(location.Y()).at(location.X());
    if (number == 0) {
      number = Board::kEmpty;
      ++empty_number_count;
    }
    SetNumber(location.X(), location.Y(), number);
  });

  SetEmptyNumberCount(empty_number_count);
}

void FullBoardTestable::SetNumber(int x, int y, Number number) {
  FullBoard::SetNumber(Location(x, y), number);
}

}
}
