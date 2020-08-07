// Copyright 2020 Magellan
#include <iostream>

#include "cpp/input_utilities.h"

void mergeSortedArrays(std::vector<int> &a, std::vector<int> &b, std::vector<int> &result) {
    int aSize{ static_cast<int> (a.size()) };
    int bSize{ static_cast<int> (b.size()) };
    int aIndex{}, bIndex{};
    while ((aIndex < aSize) && (bIndex < bSize)) {
        if (a[aIndex] < b[bIndex]) {
            result.push_back(a[aIndex++]);
        } else {
            result.push_back(b[bIndex++]);
        }
    }

    while (aIndex < aSize) {
        result.push_back(a[aIndex++]);
    }
    while (bIndex < bSize) {
        result.push_back(b[bIndex++]);
    }
}

int main() {
    std::vector<int> a;
    getInputVector(a);

    std::cout << "You have entered the vector a : ";
    for (auto &element : a) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    std::vector<int> b;
    getInputVector(b);

    std::cout << "You have entered the vector b : ";
    for (auto &element : b) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    std::vector<int> result;
    mergeSortedArrays(a, b, result);

    std::cout << "The result vector : ";
    for (auto &element : result) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}
