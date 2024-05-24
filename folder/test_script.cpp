#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "module_tested.h"


// Define your test cases
TEST_SUITE("Math Operations"){
    TEST_CASE("Addition"){
        
        SUBCASE("True") {
            int a = 1;
            int b = 2;
            int sum = a + b;
            CHECK(sum == 3);
            CHECK(sum == summation(a,b));
        }

        SUBCASE("Wrong") {
            int a = 1;
            int b = 2;
            int sum = a + b;
            CHECK_FALSE(sum == 0);
            CHECK_FALSE(sum + summation(a,b) == -1);
        }
    }
    TEST_CASE("Division"){
        SUBCASE("True") {
            double num = 6;
            double den = 2;
            CHECK(divide(num,den) == 3);
        }

        SUBCASE("Division per zero") {
            double num = 6;
            double den = 0;
            CHECK_THROWS(divide(num,den));
            CHECK(divide(den,num)==0);
        }
    }
    TEST_CASE("Subtraction") {
        int a = 5;
        int b = 3;
        int difference = a - b;
        CHECK(difference == 2);
    }
}

TEST_SUITE("Data Manipulation"){
    TEST_CASE("Loading Sample"){
        SUBCASE("Existing Sample") {
            std::string filepath = "data\\signal_features.csv";
            std::vector<std::vector<std::string>> file_content = loadCSV(filepath);
            CHECK(file_content.size() > 0);
        }

        SUBCASE("Unexisting Sample") {
            std::string filepath = "data\\unexisting.csv";
            // std::string filepath = "data\\signal_features.csv";
            std::string error_message = "Could not open file";
            CHECK_THROWS(loadCSV(filepath),error_message);
        }
    }
}

TEST_CASE("Loading Unexisting Sample 2") {
    // std::string filepath = "data\\unexisting.csv";
    std::string filepath = "data\\signal_features.csv";
    std::string error_message = "Could not open file";
    CHECK_THROWS(loadCSV(filepath),error_message);
}
