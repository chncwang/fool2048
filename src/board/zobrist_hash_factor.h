/*
 * zobrist_hash_factor.h
 *
 *  Created on: May 10, 2014
 *      Author: chncwang
 */

#ifndef ZOBRIST_HASH_FACTOR_H_
#define ZOBRIST_HASH_FACTOR_H_

#include <array>
#include <map>
#include <ostream>

#include "board/board.h"
#include "board/def.h"
#include "board/force.h"

namespace fool2048 {
namespace board {

namespace location {

class Location;

}

class ZobristHashFactor {
public:
  ~ZobristHashFactor() = default;

  static ZobristHashFactor* GetInstance();

  void Init();

  HashKey GetForceFactor(Force force) const;
  HashKey GetLocationFactor(const location::Location &location, Number number) const;

private:
  ZobristHashFactor() = default;

  friend std::ostream&
  operator<<(std::ostream &out, const ZobristHashFactor& zobrist_hash_factor);

  std::array<HashKey, 2> force_factors_;
  std::array<std::array<std::map<Number, HashKey>, Board::kBoardLength>,
  Board::kBoardLength> location_factors_;
};

} /* namespace board */
} /* namespace fool2048 */

#endif /* ZOBRIST_HASH_FACTOR_H_ */
