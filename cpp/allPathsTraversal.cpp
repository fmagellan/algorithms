// Copyright 2020 Magellan
//
// Path = Sequence of values from root to leaf.
// Problem Statement:
// Traverse all the paths, and print the path, if it has alternate odd/even numbers.
//
//         10
//     5         3
//   2   6     1   8
//
//   The solution to the above example should be
//   10 5 2
//   10 5 6
//   10 3 8

#include <iostream>
#include <vector>

class Node {
    public:
        int m_data{ 0 };
        Node *m_left{ nullptr };
        Node *m_right{ nullptr };
};

Node* newNode(const int value) {
    Node *pNode{ new Node() };
    pNode->m_data = value;

    return (pNode);
}

std::vector<int> stack;

void traverseTree(Node *pRoot) {
    if (!pRoot) {
        return;
    }
    if (!stack.empty()) {
        if (!((pRoot->m_data + stack.back()) %2)) {
            return;
        }
    }

    stack.push_back(pRoot->m_data);
    if (!pRoot->m_left && !pRoot->m_right) {
        // print.
        std::cout << "Values: ";
        for (int value : stack) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
        stack.pop_back();

        return;
    }

    traverseTree(pRoot->m_left);
    traverseTree(pRoot->m_right);
    stack.pop_back();
}

int main() {
    Node *pRoot = newNode(10);
    pRoot->m_left = newNode(5);
    pRoot->m_left->m_left = newNode(2);
    pRoot->m_left->m_right = newNode(6);
    pRoot->m_right = newNode(3);
    pRoot->m_right->m_left = newNode(1);
    pRoot->m_right->m_right = newNode(8);

    traverseTree(pRoot);

    return (0);
}
