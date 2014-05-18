/*
 * rand_util.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#include "rand_util.h"

#include <chrono>
#include <random>

using std::mt19937;
using std::uniform_real_distribution;

namespace fool2048 {

namespace {

unsigned ts = std::chrono::system_clock::now().time_since_epoch().count();

}

mt19937 gen(ts);

bool IsTrueRandomly(double rate) {
  assert(rate >= 0.0 && rate <= 1.0);
  static uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(gen) < rate;
}

}
