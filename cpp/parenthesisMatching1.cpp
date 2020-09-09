// Copyright 2020 Magellan

#include <iostream>

#include "stackArrayTemplate.h"


bool isParenthesisMatching(const char *pExpr) {
    if (!pExpr) {
        return (true);
    }

    Magellan::Stack<char> stack(100);
    for (int index{}; pExpr[index] != '\0'; ++index) {
        if (pExpr[index] == '(') {
            stack.push(pExpr[index]);
        }

        if (pExpr[index] == ')') {
            if (stack.isEmpty()) {
                // Nothing left to match. so, return false.
                return (false);
            }
            stack.pop();
        }
    }

    if (stack.isEmpty()) {
        // Empty stack after comparision. return false.
        return (true);
    }

    return (false);
}

int main() {
    const char *pExpr1 = "(a+b)-c+(d*e)";
    const char *pExpr2 = "(a+b)-c+(d*e)+f)";
    const char *pExpr3 = "(a+b)-c+(d*e)+(f";

    std::cout << std::boolalpha << isParenthesisMatching(pExpr1) << '\n';
    std::cout << std::boolalpha << isParenthesisMatching(pExpr2) << '\n';
    std::cout << std::boolalpha << isParenthesisMatching(pExpr3) << '\n';


    return (0);
}
