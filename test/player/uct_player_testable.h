/*
 * uct_player_testable.h
 *
 *  Created on: May 11, 2014
 *      Author: chncwang
 */

#ifndef UCT_PLAYER_TESTABLE_H_
#define UCT_PLAYER_TESTABLE_H_

#include "player/uct_player.h"

namespace fool2048 {
namespace player {

class UctPlayerTestable : public UctPlayer {
public:
  typedef NodeRecord NodeRecord;

  UctPlayerTestable() = default;
  ~UctPlayerTestable() = default;
};

} /* namespace player */
} /* namespace fool2048 */

#endif /* UCT_PLAYER_TESTABLE_H_ */
