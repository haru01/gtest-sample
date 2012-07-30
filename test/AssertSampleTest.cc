#include <gtest/gtest.h>

int add(int x, int y) {
    return x + y;
}


// expected == actual
TEST(AddTest, TestASSERT_TRUE_FALSE) {
    ASSERT_TRUE(1==1);
    ASSERT_FALSE(1!=1);
}


// expected == actual
TEST(AddTest, TestASSERT_EQ) {
    ASSERT_EQ(2, add(1, 1));
}

// val1 != val2
TEST(AddTest, TestASSERT_NE) {
    ASSERT_NE(4, 3);
}

// val1 < val2
TEST(AddTest, ASSERT_LT) {
    ASSERT_NE(4, 3);
}



