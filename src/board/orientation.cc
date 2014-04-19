#include "orientation.h"

using std::function;

void ForEachOrientation(
    const function<void(Orientation orientation)> &process) {
  for (int i=0; i<3; ++i) {
    process(static_cast<Orientation>(i));
  }
}
