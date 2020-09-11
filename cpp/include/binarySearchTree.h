// Copyright 2020 Magellan

#ifndef CPP_INCLUDE_BINARYSEARCHTREE_H_
#define CPP_INCLUDE_BINARYSEARCHTREE_H_

#include "cpp/include/treeTemplate.h"

namespace Magellan {

template <class T>
class BinarySearchTree : public Tree<T> {
    public:
        BinarySearchTree() = default;
        ~BinarySearchTree() = default;

        void populate() = delete;
        void insertRecursive();
        void deleteNode();

        typename Tree<T>::template Node<T> *insertRecursive(typename Tree<T>::template Node<T> *pNode, const T &value);

        typename Tree<T>::template Node<T> *deleteNode(typename Tree<T>::template Node<T> *pNode);
};

template <class T>
void BinarySearchTree<T>::insertRecursive() {
    std::cout << "Enter an element value, to insert into the Binary search tree: ";
    T value;
    std::cin >> value;

    Tree<T>::setRoot(insertRecursive(Tree<T>::getRoot(), value));
}

template <class T>
typename Tree<T>::template Node<T>* BinarySearchTree<T>::insertRecursive(typename Tree<T>::template Node<T> *pNode, const T &value) {
    if (!pNode) {
        pNode = new (typename Tree<T>::template Node<T>);
        pNode->m_data = value;
        return (pNode);
    }

    if (value < pNode->m_data) {
        pNode->m_left = insertRecursive(pNode->m_left, value);
    } else if (value > pNode->m_data) {
        pNode->m_right = insertRecursive(pNode->m_right, value);
    }

    return (pNode);
}

template <class T>
void BinarySearchTree<T>::deleteNode() {
    std::cout << "Enter an element value, to be deleted from the tree: ";
    T value;
    std::cin >> value;

    typename Tree<T>::template Node<T> *pNode{ Tree<T>::getRoot() }, *pPrevPtr{ nullptr };
    while (pNode) {
        if (value == pNode->m_data) {
            break;
        }

        pPrevPtr = pNode;
        if (value < pNode->m_data) {
            pNode = pNode->m_left;
        } else {
            pNode = pNode->m_right;
        }
    }

    if (!pNode) {
        std::cout << "Node for the value: " << value << " is not found.\n";
        return;
    }

    std::cout << "Node for the value: " << value << " is found.\n";
    if (pNode->m_left) {
        std::cout << "Height of left-tree: " << pNode->m_left->height() << '\n';
    }
    if (pNode->m_right) {
        std::cout << "Height of right-tree: " << pNode->m_right->height() << '\n';
    }
}

template <class T>
typename Tree<T>::template Node<T>* deleteNode(typename Tree<T>::template Node<T> *pNode) {
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_BINARYSEARCHTREE_H_
