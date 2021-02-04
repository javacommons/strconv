int sum(int a, int b) {
    return a + b;
}

#include "gtest/gtest.h"


TEST(MyTestCase, TestSum) {
    EXPECT_EQ(3, sum(1, 2));
}
