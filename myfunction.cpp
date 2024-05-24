#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "myfunction.h"
#include <stdexcept>


int summation(int a,int b){

    return a + b;
}


double divide(double numerator, double denominator) {
    if (denominator == 0){
        throw std::runtime_error("Division by zero");
    }
    return numerator / denominator;
}


std::vector<std::vector<std::string>> loadCSV(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}