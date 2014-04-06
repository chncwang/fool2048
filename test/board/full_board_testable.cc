#include "full_board_testable.h"

#include "board/location.h"

void FullBoardTestable::Init(const Numbers &numbers) {
  Board::ForEachLokation([this, &numbers](const Location &location) {
    auto number = numbers.at(location.Y()).at(location.X());
    if (number == 0) {
      number = Board::kEmpty;
      ++(*EmptyNumberCountPointer());
    }
    SetNumber(location.X(), location.Y(), number);
  });
}

void FullBoardTestable::SetNumber(int x, int y, Number number) {
  GetBoard()->SetNumber(Location(x, y), number);
}
