/*
 * node_record.cc
 *
 *  Created on: May 12, 2014
 *      Author: chncwang
 */

#include "uct_player.h"

#include <cassert>

#include "board/def.h"

namespace fool2048 {
namespace player {

using board::HashKey;
using std::ostream;

UctPlayer::NodeRecord::NodeRecord() : NodeRecord(0, 0.0) { }

UctPlayer::NodeRecord::NodeRecord(
    UctPlayer::NodeRecord::Times visited_times,
    float average_profit) : visited_times_(visited_times),
    average_profit_(average_profit) {
  assert(visited_times >= 0 && average_profit >= 0);
}

ostream& operator<<(ostream& out,
    const UctPlayer::NodeRecord& node_record) {
  out << "NodeRecord[visited_times_:" << node_record.visited_times_ <<
      " average_profit_:" << node_record.average_profit_;
  return out;
}

}
}