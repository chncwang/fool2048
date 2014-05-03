/*
 * force.h
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_FOARCE_H_
#define SRC_BOARD_FOARCE_H_

namespace fool2048 {
namespace board {

enum Force {
  kAddingNumber = 0,
  kMoving = 1
};

inline Force OppositeForce(Force force) {
  static Force table[2] = {kMoving, kAddingNumber};
  return table[force];
}

}
}

#endif /* SRC_BOARD_FOARCE_H_ */
