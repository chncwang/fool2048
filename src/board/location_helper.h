/*
 * location_helper.h
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_LOCATION_HELPER_H_
#define SRC_BOARD_LOCATION_HELPER_H_

#include "location.h"
#include "orientation.h"

namespace fool2048 {
namespace board {

Location GetAdjacentLocation(const Location &location, Orientation orientation);

}
}

#endif /* SRC_BOARD_LOCATION_HELPER_H_ */
