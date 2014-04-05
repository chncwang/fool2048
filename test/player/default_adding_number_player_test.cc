#include "player/default_adding_number_player.h"

#include "gtest/gtest.h"
#include "log_util.h"

TEST(DefaultAddingNumberPlayerTest, NextMove) {
  InitLogConfig();

  FullBoard full_board;
  DefaultAddingNumberPlayer player;
  const AddingNumberPlayer &adding_number_player = player;
  while (full_board.EmptyNumberCount() > 0) {
    LOG_UTIL_DEBUG("full_board: " << full_board);
    FullBoard::AddingNumberMove move =
        adding_number_player.NextMove(full_board);
    LOG_UTIL_DEBUG("move: " << move);
    full_board.PlayAddingNumberMove(move);
  }
}
