// Copyright 2020 Magellan

#include <iostream>

#include "cpp/stackArrayTemplate.h"

int main() {
    Magellan::Stack<int> stk(10);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(5);

    std::cout << "First item after pop: " << stk.pop() << '\n';
    std::cout << "Second item after pop: " << stk.pop() << '\n';
    std::cout << "Third item after pop: " << stk.pop() << '\n';

    return (0);
}
