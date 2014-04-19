#include "player/adding_number_randomly_player.h"

#include "gtest/gtest.h"
#include "board/adding_number_move.h"
#include "log_util.h"

namespace fool2048 {
namespace player {

using board::FullBoard;
using board::AddingNumberMove;

TEST(DefaultAddingNumberPlayerTest, NextMove) {
  InitLogConfig();

  FullBoard full_board;
  AddingNumberRandomlyPlayer player;
  const AddingNumberPlayer &adding_number_player = player;
  while (full_board.EmptyNumberCount() > 0) {
    LOG_UTIL_DEBUG("full_board: " << full_board);
    AddingNumberMove move = adding_number_player.NextMove(full_board);
    LOG_UTIL_DEBUG("move: " << move);
    full_board.PlayAddingNumberMove(move);
  }
}

}
}
