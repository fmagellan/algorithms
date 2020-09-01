// Copyright 2020 Magellan

// This program will print all the possible permutations of a string,
// that are possible with the characters given by the user.
// This will use a Recursive method which will use to swap the
// characters of a two given indices which keep changing
// with every call of the recursion.

#include <iostream>
#include <string>
#include <algorithm>

void permutations(std::string &str, int baseIndex) {
    int size{ static_cast<int> (str.size()) };
    if (baseIndex >= size - 1) {
        std::cout << str << '\n';
        return;
    }

    for (int incrIndex{ baseIndex }; incrIndex < size; ++incrIndex) {
        std::swap(str[baseIndex], str[incrIndex]);
        permutations(str, baseIndex + 1);
        std::swap(str[baseIndex], str[incrIndex]);
    }
}

int main() {
    std::string str{ "abcd" };

    permutations(str, 0);

    return (0);
}
