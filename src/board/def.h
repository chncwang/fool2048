/*
 * number.h
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_NUMBER_H_
#define SRC_BOARD_NUMBER_H_

#include <cstdint>

namespace fool2048 {
namespace board {

typedef uint16_t Number;
typedef uint32_t HashKey;

constexpr int kBoardLength = 4;
constexpr int kBoardLengthSquare = kBoardLength * kBoardLength;
constexpr int kLargeSideXY = kBoardLength - 1;

}
}

#endif /* SRC_BOARD_NUMBER_H_ */
