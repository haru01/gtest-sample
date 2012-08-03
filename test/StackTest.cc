#include <gtest/gtest.h>
#include <stack>
#include <iostream>

// スタックが空の場合
namespace {
  class EmptyStackTest : public ::testing::Test {
  protected:
    std::stack<int> empty;
  };

  TEST_F(EmptyStackTest, SizeIsZero) {
    ASSERT_EQ(0, empty.size());
  }
}


// スタックに要素が含まれる場合
namespace {
  class AnyStackTest : public ::testing::Test {
  protected:
    virtual void SetUp() {
      lastNode = 20;
      firstNode = 10;
      anyStack.push(firstNode);
      anyStack.push(lastNode);
    }

    // virtual void TearDown() {}
    int firstNode;
    int lastNode;
    std::stack<int> anyStack;
  };

  TEST_F(AnyStackTest, SizeIsOneMore) {
    ASSERT_LE(1, anyStack.size()) << "1 <= stack.size であること";
  }

  TEST_F(AnyStackTest, Top) {
    ASSERT_EQ(lastNode, anyStack.top());
  }

  TEST_F(AnyStackTest, Pop) {
    ASSERT_EQ(lastNode, anyStack.top());
    anyStack.pop();
    ASSERT_EQ(firstNode, anyStack.top());
    ASSERT_EQ(firstNode, anyStack.top());
  }
}