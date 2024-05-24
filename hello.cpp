#include <iostream>
#include "gtest/gtest.h"

TEST(HelloTest, HelloWorld) {
    std::cout << "Hello, World!" << std::endl;
    ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}