/*
 * number_util.cc
 *
 *  Created on: May 14, 2014
 *      Author: chncwang
 */

#include "board/number_util.h"

#include <cassert>

#include <map>

#include "log_util.h"
#include "board/board.h"

namespace fool2048 {
namespace board {

using log4cplus::Logger;
using std::map;
using std::make_pair;

namespace {

Logger LOG = Logger::getInstance("fool2048.board.NumberUtil");

}

int GetLevel(Number number) {
  static map<Number, int> s_map;

  assert(number != Board::kEmpty);
  Validate(number);

  int level;
  auto iterator = s_map.find(number);

  if (iterator == s_map.end()) {
    LOG_UTIL_TRACE(LOG, "result not found in map");
    level = 0;
    Number t = number;
    while (t >= 2) {
      ++level;
      t >>= 1;
    }

    s_map.insert(make_pair(number, level));
  } else {
    LOG_UTIL_TRACE(LOG, "result already in map");
    level = iterator->second;
  }

  return level;
}

void Validate(Number number) {
  LOG_UTIL_DEBUG(LOG, "number" << number);
  assert(number > 0 || number == Board::kEmpty);
  assert((number & (number - 1)) == 0);
}

}
}