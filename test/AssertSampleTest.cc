#include <gtest/gtest.h>
#include "../src/add.h"


TEST(AddTest, TestASSERT_TRUE_FALSE) {
    ASSERT_TRUE(1==1);
    ASSERT_FALSE(1!=1);
}

TEST(AddTest, TestASSERT_EQ) {
    ASSERT_EQ(2, add(1, 1)) << "expected == actual";
}

TEST(AddTest, TestASSERT_NE) {
    ASSERT_NE(4, 3) << "val1 != val2";
}

TEST(AddTest, ASSERT_LT) {
    ASSERT_LT(4, add(1, 4)) << "val1 < val2";
}

TEST(AddTest, ASSERT_GT) {
    ASSERT_GT(6, add(1, 4)) << "val1 > val2";
}


TEST(AddTest, ASSERT_LE) {
    ASSERT_LE(4, add(1, 4)) << "val1 <= val2";
    ASSERT_LE(5, add(1, 4)) << "val1 <= val2";
}

TEST(AddTest, ASSERT_GE) {
    ASSERT_GE(5, add(1, 4)) << "val1 <= val2";
    ASSERT_GE(6, add(1, 4)) << "val1 <= val2";
}

