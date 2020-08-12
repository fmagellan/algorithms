// Copyright 2020 Magellan
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "cpp/input_utilities.h"

int main() {
    std::vector<int> vecFileSize;
    getInputVector(vecFileSize);

    std::cout << "File sizes: ";
    for (auto fileSize : vecFileSize) {
        std::cout << fileSize << ' ';
    }

    std::cout << '\n';

    std::make_heap(vecFileSize.begin(), vecFileSize.end(), std::greater<>{});

    std::cout << "File sizes after arranging int the Min heap: ";
    for (auto fileSize : vecFileSize) {
        std::cout << fileSize << ' ';
    }

    std::cout << '\n';

    int accumulator{};
    while (vecFileSize.size() > 1) {
        std::pop_heap(vecFileSize.begin(), vecFileSize.end(), std::greater<>{});
        int min1{ vecFileSize.back() };
        vecFileSize.pop_back();

        std::pop_heap(vecFileSize.begin(), vecFileSize.end(), std::greater<>{});
        int min2{ vecFileSize.back() };
        vecFileSize.pop_back();

        int result{ min1 + min2 };
        accumulator += result;
        vecFileSize.push_back(result);
        std::push_heap(vecFileSize.begin(), vecFileSize.end(), std::greater<>{});
    }

    std::cout << "Accumulator in the optimal merge way: " << accumulator << '\n';

    return (0);
}
