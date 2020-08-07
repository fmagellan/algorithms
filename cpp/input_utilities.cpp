// Copyright 2020 Magellan
#include <iostream>
#include <string>
#include <sstream>

#include "cpp/input_utilities.h"

void getInputVector(std::vector<int> &vec) {
    std::cout << "Enter the vector to be sorted: ";
    std::string str{};
    std::getline(std::cin, str);

    std::stringstream inStream(str);
    int element{};
    while (inStream >> element) {
        vec.push_back(element);
    }
}
