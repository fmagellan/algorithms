// Copyright 2020 Magellan
#include <iostream>
#include <string>
#include <sstream>

#include "input_utilities.h"

void getInputVector(std::vector<int> &vec) {
    std::cout << "Enter the vector: ";
    std::string str{};
    std::getline(std::cin, str);

    std::stringstream inStream(str);
    int element{};
    while (inStream >> element) {
        vec.push_back(element);
    }
}
