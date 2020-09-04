// Copyright 2020 Magellan

#include <iostream>

#include "cpp/stackLinkedListTemplate.h"

int main() {
    Magellan::Stack<int> stack;
    stack.push_back(15);
    stack.push_back(16);
    stack.push_back(17);

    stack.display();
    std::cout << "Popping: " << stack.pop_back() << '\n';

    stack.display();

    return (0);
}
