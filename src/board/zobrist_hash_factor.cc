/*
 * zobrist_hash_factor.cc
 *
 *  Created on: May 10, 2014
 *      Author: chncwang
 */

#include "board/zobrist_hash_factor.h"

#include "board/full_board.h"
#include "board/location/location.h"
#include "log_util.h"
#include "rand_util.h"

namespace fool2048 {
namespace board {

using location::Location;
using log4cplus::Logger;
using std::endl;
using std::make_pair;
using std::ostream;

namespace {

Logger LOG = Logger::getInstance("fool2048.board.ZobristHashFactor");

}

ZobristHashFactor* ZobristHashFactor::GetInstance() {
  static ZobristHashFactor ins;
  static bool inited;
  if (!inited) {
    inited = true;
    ins.Init();
  }
  return &ins;
}

void ZobristHashFactor::Init() {
  LOG_UTIL_TRACE(LOG, "Init begin.");

  for (HashKey &force_factor : force_factors_) {
    force_factor = NextRandomNumber<HashKey>();
  }

  for (auto &row : location_factors_) {
    for (auto &map : row) {
      for (Number num = 2; num <= FullBoard::kMaxPossibleNumber; num <<= 1) {
        LOG_UTIL_DEBUG(LOG, "num " << num);
        map.insert(make_pair(num, NextRandomNumber<HashKey>()));
      }

      map.insert(make_pair(Board::kEmpty, NextRandomNumber<HashKey>()));
    }
  }

  LOG_UTIL_TRACE(LOG, "Init end.");
}

HashKey ZobristHashFactor::GetForceFactor(Force force) const {
  return force_factors_.at(force);
}

HashKey ZobristHashFactor::GetLocationFactor(const Location& location,
    Number number) const {
  return location_factors_.at(location.Y()).at(location.X()).at(number);
}

ostream& operator<<(std::ostream &out,
    const ZobristHashFactor& zobrist_hash_factor) {
  out << "force_factors_[0] " << zobrist_hash_factor.force_factors_.at(0) <<
      endl;
  out << "force_factors_[1] " << zobrist_hash_factor.force_factors_.at(1) <<
      endl;
  out << "location_factors_" << endl;

  for (int y = 0; y < kBoardLength; ++y) {
    for (int x = 0; x < kBoardLength; ++x) {
      out << "x " << x << " y " << y << endl;
      const auto &map = zobrist_hash_factor.location_factors_.at(y).at(x);
      for (auto &kv : map) {
        out << "key " << kv.first << " value " << kv.second << endl;
      }
    }
  }
}

} /* namespace board */
} /* namespace fool2048 */
