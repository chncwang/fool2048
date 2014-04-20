/*
 * rand_util.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef SRC_RAND_UTIL_H_
#define SRC_RAND_UTIL_H_

namespace fool2048 {

int NextRandomNumber(int upper_bound);

bool IsTrueRandomly(double rate);

}

#endif /* SRC_RAND_UTIL_H_ */
