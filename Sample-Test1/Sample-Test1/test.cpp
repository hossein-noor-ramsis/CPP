#include "pch.h"

int add(int a, int b) {
	return a + b;
}

TEST(AdditionTest, PositiveNumbers) {
	EXPECT_EQ(add(1, 2), 3);
	EXPECT_EQ(add(10, 20), 30);
}

TEST(AdditionTest, NegativeNumbers) {
	EXPECT_EQ(add(-1, -2), -3);
	EXPECT_EQ(add(-10, -20), -30);
}
