/*
 * location.h
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <ostream>

#include "def.h"

namespace fool2048 {
namespace board {

class Location {
public:
  Location() :
      x_(0), y_(0) {
  }

  Location(int x, int y) {
    x_ = x;
    y_ = y;
  }

  Location(Location &&location) = default;

  ~Location() = default;

  void Copy(const Location &location) {
    x_ = location.x_;
    y_ = location.y_;
  }

  int X() const {
    return x_;
  }

  int Y() const {
    return y_;
  }

  DISALLOW_COPY_AND_ASSIGN(Location);

private:
  friend bool IsEqual(const Location &a, const Location &b) {
    return a.x_ == b.x_ && a.y_ == b.y_;
  }

  friend std::ostream& operator<<(std::ostream& out, const Location &location) {
    out << "[x_:" << location.x_ << ", y_:" << location.y_ << "]";
    return out;
  }

  int x_;
  int y_;
};

}
}

#endif /* LOCATION_H_ */
