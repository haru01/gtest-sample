#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stack>
#include <iostream>
using ::testing::AtLeast;
using ::testing::Return;

class SameDayChecker {
public:
  virtual bool hasExpired() = 0;
};

class StubSameDayChecker : public SameDayChecker {
public:
  MOCK_METHOD0(hasExpired, bool());
};

class Receiver {
private:
  SameDayChecker* checker;

public:
  Receiver(SameDayChecker* _checker) {
    checker = _checker;
  }

  bool acceptRequest(int code) {
    if (checker->hasExpired()) {
      // ...何か処理
      return false;
    } else {
      // ... 何か処理
      return true;
    }
  }
};

TEST(AddTest, rejectsRequestsOutsideAllowedPeriod) {
  StubSameDayChecker checker;
  ON_CALL(checker, hasExpired())
      .WillByDefault(Return(true));
  Receiver receiver(&checker);

  ASSERT_FALSE(receiver.acceptRequest(200));
}