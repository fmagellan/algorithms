// Copyright 2020 Magellan
// This program will convert an valid mathematical expression in infix format
// and will convert it to postfix format.

// Assumptions:
// 1. Expression will be less than 100 characters long.
// 2. The operands will be of single character.

#include <iostream>

#include "cpp/stackArrayTemplate.h"

bool isOperator(const char op) {
    if ((op == '+') || (op == '-') || (op == '/') || (op == '*')) {
        return (true);
    }

    return (false);
}

int getOperatorPriority(const char op) {
    if ((op == '+') || (op == '-')) {
        return (1);
    }

    if ((op == '*') || (op == '/')) {
        return (2);
    }

    return (0);
}

char *convertInfixToPostfix(const char *pInfix) {
    if (!pInfix) {
        return (nullptr);
    }

    char *pPostfix{ new char[100] };
    int indexInfix{}, indexPostfix{};
    Magellan::Stack<char> stack(100);

    while (pInfix[indexInfix] != '\0') {
        if (isOperator(pInfix[indexInfix])) {
            if (stack.isEmpty()) {
                stack.push(pInfix[indexInfix++]);
                continue;
            }

            const char topOperatorInStack{ stack.back() };
            if (getOperatorPriority(topOperatorInStack) >= getOperatorPriority(pInfix[indexInfix])) {
                pPostfix[indexPostfix++] = stack.pop();
            } else {
                stack.push(pInfix[indexInfix++]);
            }
        } else {
            pPostfix[indexPostfix++] = pInfix[indexInfix++];
        }
    }

    while (!stack.isEmpty()) {
        pPostfix[indexPostfix++] = stack.pop();
    }

    pPostfix[indexPostfix] = '\0';

    return (pPostfix);
}

int main() {
    const char *pInfix1{ "2+3*4" };
    const char *pInfix2{ "2+3*4+6/2" };
    const char *pInfix3{ "2+3*4+6/2*3" };
    const char *pInfix4{ "6/2*3" };

    char *pPostfix1{ convertInfixToPostfix(pInfix1) };
    std::cout << "Infix: " << pInfix1 << ", Postfix: " << pPostfix1 << '\n';
    char *pPostfix2{ convertInfixToPostfix(pInfix2) };
    std::cout << "Infix: " << pInfix2 << ", Postfix: " << pPostfix2 << '\n';
    char *pPostfix3{ convertInfixToPostfix(pInfix3) };
    std::cout << "Infix: " << pInfix3 << ", Postfix: " << pPostfix3 << '\n';
    char *pPostfix4{ convertInfixToPostfix(pInfix4) };
    std::cout << "Infix: " << pInfix4 << ", Postfix: " << pPostfix4 << '\n';

    return (0);
}
