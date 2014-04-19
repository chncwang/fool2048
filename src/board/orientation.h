/*
 * orientation.h
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */

#ifndef ORIENTATION_H_
#define ORIENTATION_H_

#include <functional>

enum Orientation {
  kRight = 0, kUp = 1, kLeft = 2, kDown = 3
};

inline Orientation OppositeOrientation(Orientation orientation) {
  static const Orientation kTable[4] = { Orientation::kLeft, Orientation::kDown,
      Orientation::kRight, Orientation::kUp };
  return kTable[orientation];
}

void ForEachOrientation(
    const std::function<void(Orientation orientation)> &process);

#endif /* ORIENTATION_H_ */
