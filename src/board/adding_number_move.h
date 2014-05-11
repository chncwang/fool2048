/*
 * adding_number_move.h
 *
 *  Created on: Apr 6, 2014
 *      Author: chncwang
 */

#ifndef SRC_BOARD_ADDING_NUMBER_MOVE_H_
#define SRC_BOARD_ADDING_NUMBER_MOVE_H_

#include <ostream>

#include "board/location/location.h"

namespace fool2048 {
namespace board {

class AddingNumberMove {
public:

  enum InitialNumber {
    kTwo = 2, kFour = 4
  };

  AddingNumberMove(const location::Location &location,
      InitialNumber initial_number) :
      initial_number_(initial_number) {
    location_.Copy(location);
  }

  AddingNumberMove(AddingNumberMove &&adding_number_move) = default;

  const location::Location& GetLocation() const {
    return location_;
  }

  InitialNumber GetInitialNumber() const {
    return initial_number_;
  }

  DISALLOW_COPY_AND_ASSIGN(AddingNumberMove);

private:

  friend std::ostream& operator<<(std::ostream &out,
      const AddingNumberMove &adding_number_move) {
    out << "[location_:" << adding_number_move.location_ << ", initial_number_:"
        << adding_number_move.initial_number_ << "]";
    return out;
  }

  location::Location location_;
  InitialNumber initial_number_;
};

}
}

#endif /* SRC_BOARD_ADDING_NUMBER_MOVE_H_ */
