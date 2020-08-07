// Copyright 2020 Magellan
#include <iostream>
#include "cpp/input_utilities.h"

// Assumption.
// First array is from low to mid, and is in sorted order.
// Second array is from mid+1 to high, and is in sorted order.
// Get a temp-array, which copies elements in sorted order.
// Copy the temp-array, to the main-array, from low-high.
void mergeAndReplace(std::vector<int> &vec, int lowIndex, int highIndex) {
    std::vector<int> result;
    int firstIndex{ lowIndex };
    int midIndex{ static_cast<int> ((lowIndex + highIndex)/2) };
    int secondIndex{ midIndex + 1 };

    while ((firstIndex <= midIndex) && (secondIndex <= highIndex)) {
        if (vec[firstIndex] < vec[secondIndex]) {
            result.push_back(vec[firstIndex++]);
        } else {
            result.push_back(vec[secondIndex++]);
        }
    }

    while (firstIndex <= midIndex) {
        result.push_back(vec[firstIndex++]);
    }
    while (secondIndex <= highIndex) {
        result.push_back(vec[secondIndex++]);
    }

    int resultSize{ static_cast<int> (result.size()) };
    for (int copyIndex{}; copyIndex < resultSize; copyIndex++) {
        vec[lowIndex + copyIndex] = result[copyIndex];
    }
}

void mergeSort(std::vector<int> &vec, int lowIndex, int highIndex) {
    int midIndex{ (lowIndex + highIndex)/2 };
    if (lowIndex < midIndex) {
        mergeSort(vec, lowIndex, midIndex);
        mergeSort(vec, midIndex + 1, highIndex);
    }
    mergeAndReplace(vec, lowIndex, highIndex);
}


int main() {
    std::vector<int> vec;
    getInputVector(vec);
    
    std::cout << "You have entered the vector: ";
    for (auto &element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

//    mergeAndReplace(vec, 0, static_cast<int> (vec.size()) - 1);
    mergeSort(vec, 0, static_cast<int> (vec.size()) - 1);

    std::cout << "The sorted vector: ";
    for (auto &element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}
