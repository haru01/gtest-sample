#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
using ::testing::AtLeast;
using ::testing::Return;

using ::testing::NiceMock;
using ::testing::StrictMock;

class Foo {
public:
  virtual void DoThis() = 0;
  virtual void NotSetExpectCall() = 0;
};


class MockFoo : public Foo {
public:
  MOCK_METHOD0(DoThis, void());
  MOCK_METHOD0(NotSetExpectCall, void());
};

// EXPECT_CALL で宣言した通り、DoThisメソッドを呼び出す事で テストはパスする。
TEST(AddTest, MockEXPECT_CALL_SampleTest) {
  MockFoo mock_foo;
  EXPECT_CALL(mock_foo, DoThis());

  mock_foo.DoThis(); //（この行をコメントアウトすればテストは失敗）
}

// NiceMockの場合、EXPECT_CALL で設定していないメソッドを呼び出してもテストはパスする。警告も出ない。
TEST(AddTest, NiceMockTest) {
  NiceMock<MockFoo> mock_foo;

  mock_foo.NotSetExpectCall(); //（コメントアウトするしない関わらずテストはパスする
}

// StrictMockTestの場合、EXPECT_CALL で設定していないメソッドを呼び出だせばテストは失敗する。
TEST(AddTest, StrictMockTest) {
  StrictMock<MockFoo> mock_foo;

  // mock_foo.NotSetExpectCall(); //（コメントアウトを外すとテストは失敗する
}