#include "board/zobrist_hash_factor.h"

#include "gtest/gtest.h"

#include "log_util.h"
#include "board/location/location.h"

namespace fool2048 {
namespace board {

using location::Location;
using log4cplus::Logger;

namespace {

class ZobristHashFactorTest : public ::testing::Test {

 protected:

  virtual void SetUp() {
    InitLogConfig();
    ins_ = ZobristHashFactor::GetInstance();
  }

  ZobristHashFactor *ins_;
};

Logger LOG = Logger::getInstance("fool2048.board.ZobristHashFactorTest");

}

TEST_F(ZobristHashFactorTest, Init) {
  LOG_UTIL_DEBUG(LOG, "zobrist_hash_factor" << *ins_);
}

TEST_F(ZobristHashFactorTest, GetForceFactor) {
  ins_ = ZobristHashFactor::GetInstance();
  LOG_UTIL_DEBUG(LOG, "force 0 " << ins_->GetForceFactor(Force::kAddingNumber));
  LOG_UTIL_DEBUG(LOG, "force 1 " << ins_->GetForceFactor(Force::kMoving));
}

TEST_F(ZobristHashFactorTest, GetLocationFactor) {
  ins_ = ZobristHashFactor::GetInstance();
  LOG_UTIL_DEBUG(LOG, "location 3 3 2048 " <<
      ins_->GetLocationFactor(Location(3, 3), 2048));
}

}
}
