/*
 * number_util.h
 *
 *  Created on: May 14, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_NUMBER_UTIL_H_
#define SRC_BOARD_NUMBER_UTIL_H_

#include "board/def.h"

namespace fool2048 {
namespace board {

int GetLevel(Number number);

void Validate(Number number);

}
}

#endif /* SRC_BOARD_NUMBER_UTIL_H_ */
