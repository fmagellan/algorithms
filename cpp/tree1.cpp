// Copyright 2020 Magellan

#include "include/treeTemplate.h"

int main() {
    Magellan::Tree<int> tree;
    tree.populate();
    tree.displayInOrder();

    return (0);
}
