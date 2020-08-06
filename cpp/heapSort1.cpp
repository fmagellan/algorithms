// Copyright 2020 Magellan
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

void heapify(std::vector<int> &vec, const int numElementsInHeap, const int rootIndex) {
    int leftIndex{ 2 * rootIndex + 1 };
    int rightIndex{ 2 * rootIndex + 2 };
    int largeIndex{ rootIndex };

    if ((leftIndex < numElementsInHeap) && (vec[leftIndex] > vec[largeIndex])) {
        largeIndex = leftIndex;
    }

    if ((rightIndex < numElementsInHeap) && (vec[rightIndex] > vec[largeIndex])) {
        largeIndex = rightIndex;
    }

    if (rootIndex != largeIndex) {
        std::swap(vec[rootIndex], vec[largeIndex]);
        heapify(vec, numElementsInHeap, largeIndex);
    }
}

int main() {
    // 1. Get input vector
    std::vector<int> vec;
    getInputVector(vec);

    std::cout << "You have entered the vector: ";
    for (auto &element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    // 2. Heapify it, for the Max-heap
    //    Do this for all the non-leaf elements.
    const int size{ static_cast<int>(vec.size()) };
    for (int index = (size / 2) - 1; index >= 0; --index) {
        heapify(vec, size, index);
    }
    std::cout << "After heapify: ";
    for (auto &element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    // 3. Do the sorting, now.
    for (int index = size - 1; index >= 0; --index) {
        // The root element is always the largest value in the heap.
        // So, swap it with the last element in the vector.
        // The heapify the rest of the vector.
        // Repeat the process !
        std::swap(vec[0], vec[index]);
        heapify(vec, index, 0);
    }
    std::cout << "After sort: ";
    for (auto &element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    return (0);
}
