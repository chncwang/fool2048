/*
 * full_board_game.cc
 *
 *  Created on: Apr 9, 2014
 *      Author: chncwang
 */

#include "board/full_board_game.h"

#include "board/def.h"
#include "board/board.h"
#include "board/board_helper.h"
#include "board/full_board.h"
#include "board/location/location_helper.h"
#include "log_util.h"

namespace fool2048 {
namespace board {

using location::ForEachOrientation;
using location::Orientation;
using log4cplus::Logger;
using std::vector;

namespace {

Logger LOG = Logger::getInstance("fool2048.board.FullBoardGame");

}

bool HasGameEnded(const FullBoard &full_board) {
  bool ended = true;

  if (full_board.EmptyNumberCount() > 0) {
    ended = false;
  } else {
    for (int i = 0; i < 4; ++i) {
      if (IsMovable(full_board, static_cast<Orientation>(i))) {
        ended = false;
        break;
      }
    }
  }

  return ended;
}

bool IsMovable(const FullBoard &full_board, Orientation orientation) {
  FullBoard copied_full_board;
  LOG_UTIL_DEBUG(LOG, "full_board " << full_board);
  copied_full_board.Copy(full_board);
  LOG_UTIL_DEBUG(LOG, "copied_full_board " << copied_full_board);
  copied_full_board.PlayMovingMove(orientation);

  return !IsEqual(full_board.GetBoard(), copied_full_board.GetBoard());
}

vector<Orientation> MovableOrientations(const FullBoard &full_board) {
  vector<Orientation> orientations;

  ForEachOrientation([&orientations, &full_board](Orientation orientation) {
    if (IsMovable(full_board, orientation)) {
      orientations.push_back(orientation);
    }
  });

  return orientations;
}

}
}
