// Copyright 2020 Magellan

#include "cpp/include/binarySearchTree.h"

int main() {
    Magellan::BinarySearchTree<int> tree;
    tree.recursiveInOrderDisplay();
    tree.insertRecursive();
    tree.insertRecursive();
    tree.insertRecursive();
    tree.insertRecursive();
    tree.insertRecursive();
    tree.insertRecursive();
    tree.insertRecursive();
    tree.recursiveInOrderDisplay();
    tree.recursivePreOrderDisplay();
    tree.recursivePostOrderDisplay();
    tree.deleteNode();


    return (0);
}
