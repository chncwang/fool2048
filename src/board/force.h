/*
 * force.h
 *
 *  Created on: Apr 12, 2014
 *      Author: chncwang
 */

#ifndef FORCE_H_
#define FORCE_H_

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

#endif /* FORCE_H_ */
