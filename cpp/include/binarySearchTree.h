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

        typename Tree<T>::template Node<T>* insertRecursive(typename Tree<T>::template Node<T> *pNode, const T &value);

        typename Tree<T>::template Node<T>* deleteNode(typename Tree<T>::template Node<T> *pNode, const T &value);
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

    Tree<T>::setRoot(deleteNode(Tree<T>::getRoot(), value));
}

template <class T>
typename Tree<T>::template Node<T>* BinarySearchTree<T>::deleteNode(typename Tree<T>::template Node<T> *pRootNode, const T &value) {
    if (!pRootNode) {
        return (pRootNode);
    }

    if (value < pRootNode->m_data) {
        pRootNode->m_left = deleteNode(pRootNode->m_left, value);
        return (pRootNode);
    } else if (value > pRootNode->m_data) {
        pRootNode->m_right = deleteNode(pRootNode->m_right, value);
        return (pRootNode);
    }

    // The current node has to be deleted.
    // Find the successor node, copy it's value to the current node, and delete the successor value.
    if (!pRootNode->m_left) {
        typename Tree<T>::template Node<T> *pTempNode{ pRootNode->m_right };
        pRootNode->m_right = nullptr;
        delete (pRootNode);
        return (pTempNode);
    } else if (!pRootNode->m_right) {
        typename Tree<T>::template Node<T> *pTempNode{ pRootNode->m_left };
        pRootNode->m_left = nullptr;
        delete (pRootNode);
        return (pTempNode);
    }

    int heightLeftSubTree{}, heightRightSubTree{};
    if (pRootNode->m_left) {
        heightLeftSubTree = pRootNode->m_left->height();
    }
    if (pRootNode->m_right) {
        heightRightSubTree = pRootNode->m_right->height();
    }

    if (heightLeftSubTree > heightRightSubTree) {
        typename Tree<T>::template Node<T> *pSuccessorNode{ nullptr }, *pTempNode{ pRootNode->m_left };
        while (pTempNode) {
            pSuccessorNode = pTempNode;
            pTempNode = pTempNode->m_right;
        }

        if (pSuccessorNode) {
            pRootNode->m_data = pSuccessorNode->m_data;
            pRootNode->m_left = deleteNode(pRootNode->m_left, pSuccessorNode->m_data);
        } else {
            pRootNode->m_left = nullptr;
        }
    } else {
        typename Tree<T>::template Node<T> *pSuccessorNode{ nullptr }, *pTempNode{ pRootNode->m_right };
        while (pTempNode) {
            pSuccessorNode = pTempNode;
            pTempNode = pTempNode->m_left;
        }

        if (pSuccessorNode) {
            pRootNode->m_data = pSuccessorNode->m_data;
            pRootNode->m_right = deleteNode(pRootNode->m_right, pSuccessorNode->m_data);
        } else {
            pRootNode->m_right = nullptr;
        }
    }

    return (pRootNode);
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_BINARYSEARCHTREE_H_
