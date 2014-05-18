/*
 * rand_util.h
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#ifndef SRC_RAND_UTIL_H_
#define SRC_RAND_UTIL_H_

#include <cassert>

#include <chrono>
#include <typeinfo>
#include <random>

#include "log_util.h"

namespace fool2048 {

using log4cplus::Logger;

extern std::mt19937 gen;

template <typename T>
T NextRandomNumber(T upper_bound) {
  assert(upper_bound > 0);
  std::uniform_int_distribution<T> distribution(0, upper_bound - 1);
  return distribution(gen);
}

template <typename T>
T NextRandomNumber() {
  std::uniform_int_distribution<T> distribution;
  return distribution(gen);
}

bool IsTrueRandomly(double rate);

}

#endif /* SRC_RAND_UTIL_H_ */
