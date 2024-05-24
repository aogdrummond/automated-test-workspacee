#include <gtest/gtest.h>
#include "myfunction.h"

// Helper function to check division
void testDivision(float dividend, float divisor, float expected_quotient = 0) {
    if (divisor == 0){
        EXPECT_THROW(divide(1,0),std::runtime_error);
    } else {
        EXPECT_EQ(divide(dividend, divisor), expected_quotient);
    }
    
}

// Test suite for mathematical operations
class OperationsTest : public ::testing::Test {
protected:
    int a; int b; int c; int zero;
    // SetUp function to initialize common objects or data
    void SetUp() override {
        // Add common setup code here if needed
        a = 2;
        b = 3;
        c = 2;
        zero = 0;
    }
};

// Test suite for division
TEST_F(OperationsTest, Division) {
    int expected1 = 1;
    double expected2 = 1.5;
    testDivision(a, c, expected1);
    testDivision(b, c, expected2);
}

TEST_F(OperationsTest, DivisionPerZero) {
    testDivision(a, zero);
}

// Test suite for subtraction
TEST_F(OperationsTest, Subtraction) {
    int expected1 = -1;
    int expected2 = 1;
    EXPECT_EQ(a - b, expected1);
    EXPECT_EQ(b - a, expected2);
}

// Test suite for data manipulation
class DataManipulationTest : public ::testing::Test {
protected:
    std::string filePath;
    std::string wrongFilePath;
    // SetUp function to initialize common objects or data
    void SetUp() override {
        // Add common setup code here if needed
        filePath = "data/signal_features.csv";
        wrongFilePath = "data/wrongpath.csv";
    }
};

// Test case for loading data from CSV
TEST_F(DataManipulationTest, LoadFromCSV) {
    
    EXPECT_GT(loadCSV(filePath).size(), 0);
    EXPECT_THROW(loadCSV(wrongFilePath), std::runtime_error);
}

// Main function to run all tests
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}