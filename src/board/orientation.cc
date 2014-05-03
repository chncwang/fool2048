#include "orientation.h"

using std::function;

namespace fool2048 {
namespace board {

void ForEachOrientation(
    const function<void(Orientation orientation)> &process) {
  for (int i=0; i<4; ++i) {
    process(static_cast<Orientation>(i));
  }
}

}
}
