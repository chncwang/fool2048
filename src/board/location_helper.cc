/*

 * location_helper.cc
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */
#include "location_helper.h"

namespace fool2048 {
namespace board {

Location GetAdjacentLocation(const Location &location, Orientation orientation) {
  static const int kOrientationUnit[4][2] = { 1, 0, 0, -1, -1, 0, 0, 1 };
  return Location(location.X() + kOrientationUnit[orientation][0],
      location.Y() + kOrientationUnit[orientation][1]);
}

}
}
