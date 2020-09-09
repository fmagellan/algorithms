// Copyright 2020 Magellan

#include "include/treeTemplate.h"

int main() {
    Magellan::Tree<int> tree;
    tree.populate();
    tree.recursiveInOrderDisplay();
    tree.recursivePreOrderDisplay();
    tree.recursivePostOrderDisplay();
    tree.linearInOrderDisplay();
    tree.linearPreOrderDisplay();

    return (0);
}
