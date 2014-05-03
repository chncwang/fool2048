/*
 * rand_util.cc
 *
 *  Created on: Mar 23, 2014
 *      Author: chncwang
 */

#include "rand_util.h"

#include <cassert>

#include <chrono>
#include <random>

using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
namespace chrono = std::chrono;

namespace {

unsigned ts = chrono::system_clock::now().time_since_epoch().count();
mt19937 gen(ts);

}

namespace fool2048 {

int NextRandomNumber(int upper_bound) {
  assert (upper_bound > 0);
  uniform_int_distribution<uint32_t> distribution(0, upper_bound - 1);
  return distribution(gen);
}


bool IsTrueRandomly(double rate) {
  assert(rate >= 0.0 && rate <= 1.0);
  static uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(gen) < rate;
}

}
