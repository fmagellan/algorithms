// Copyright 2020 Magellan

#include "cpp/include/avlTree.h"

int main() {
    Magellan::AvlTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.recursiveInOrderDisplay();
    tree.recursivePreOrderDisplay();
}
