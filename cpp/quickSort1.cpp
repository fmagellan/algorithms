// Copyright 2020 Magellan
#include <iostream>

#include "cpp/input_utilities.h"

int partition(std::vector<int> &vec, int lowIndex, int highIndex) {
    int pivotIndex{ highIndex };
    int highestLowerValueIndex{ lowIndex - 1 };

    for (int lowerValueIndex{ lowIndex }; lowerValueIndex < highIndex; ++lowerValueIndex) {
        if (vec[lowerValueIndex] < vec[pivotIndex]) {
            highestLowerValueIndex++;
            std::swap(vec[highestLowerValueIndex], vec[lowerValueIndex]);
        }
    }

    pivotIndex = highestLowerValueIndex + 1;
    std::swap(vec[pivotIndex], vec[highIndex]);

    return (pivotIndex);
}

void quickSort(std::vector<int> &vec, int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int partitionIndex = partition(vec, lowIndex, highIndex);

        quickSort(vec, 0, partitionIndex - 1);
        quickSort(vec, partitionIndex + 1, highIndex);
    }
}

int main() {
    std::vector<int> vec;
    getInputVector(vec);

    std::cout << "You have entered the vector: ";
    for (auto &element: vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    quickSort(vec, 0, static_cast<int> (vec.size()) - 1);

    std::cout << "You have entered the vector: ";
    for (auto &element: vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}
