// Copyright 2020 Magellan

#include "cpp/include/avlTree.h"

int main() {
    Magellan::AvlTree<int> tree;
    tree.insertValue(1);
    tree.insertValue(2);
    tree.insertValue(3);
    tree.insertValue(4);
    tree.insertValue(5);
    tree.insertValue(6);
    tree.insertValue(7);
    tree.insertValue(8);
    tree.insertValue(9);
    tree.insertValue(10);
    tree.recursiveInOrderDisplay();
    tree.recursivePreOrderDisplay();

    tree.deleteValue(1);
    tree.recursiveInOrderDisplay();
    tree.recursivePreOrderDisplay();
    tree.deleteValue(3);
    tree.recursiveInOrderDisplay();
    tree.recursivePreOrderDisplay();
}
