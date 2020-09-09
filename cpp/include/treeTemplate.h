// Copyright 2020 Magellan
#ifndef CPP_INCLUDE_TREETEMPLATE_H_
#define CPP_INCLUDE_TREETEMPLATE_H_

#include <iostream>

namespace Magellan {

template <class T>
class Node {
    public:
        T m_data;
        Node *m_left{ nullptr };
        Node *m_right{ nullptr };
        ~Node();

    private:
        void freeNode(Node *pNode);
};

template <class T>
Node<T>::~Node<T> () {
    freeNode(m_left);
    freeNode(m_right);
}

template <class T>
void Node<T>::freeNode(Node<T> *pNode) {
    if (!m_left) {
        freeNode(m_left);
    }

    if (!m_right) {
        freeNode(m_right);
    }

    free(pNode);
}

template <class T>
class Tree {
    private:
        Node<T> *m_root{ nullptr };

    public:
        Tree() = default;
        ~Tree();

        void displayInOrder();
        void populate();
        void populateNode(Node<T> *pParentNode, const bool leftchild);

    private:
        void inOrderTraversal(Node<T> *pNode);
};

template <class T>
Tree<T>::~Tree<T> () {
    delete (m_root);
}

template <class T>
void Tree<T>::populate() {
    std::cout << "Enter the value for root: ";
    T item;
    std::cin >> item;
    if (!item) {
        return;
    }

    m_root = new Node<T>;
    m_root->m_data = item;
    std::cout << "Enter the value for left child for " << item << ": ";
    populateNode(m_root, true);
    std::cout << "Enter the value for right child for " << item << ": ";
    populateNode(m_root, false);
}

template <class T>
void Tree<T>::populateNode(Node<T> *pParentNode, const bool leftChild) {
    T item;
    std::cin >> item;
    if (!item) {
        return;
    }

    // Add data.
    Node<T> *pNode{ new Node<T> };
    pNode->m_data = item;
    if (leftChild) {
        pParentNode->m_left = pNode;
    } else {
        pParentNode->m_right = pNode;
    }

    // Add Left child.
    std::cout << "Enter the value for left child for " << item << ": ";
    populateNode(pNode, true);
    std::cout << "Enter the value for right child for " << item << ": ";
    populateNode(pNode, false);
}

template <class T>
void Tree<T>::displayInOrder() {
    std::cout << "Tree: ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    inOrderTraversal(m_root);
    std::cout << "\n";
}

template <class T>
void Tree<T>::inOrderTraversal(Node<T> *pNode) {
    if (!pNode) {
        return;
    }

    inOrderTraversal(pNode->m_left);
    std::cout << pNode->m_data << ' ';
    inOrderTraversal(pNode->m_right);
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_TREETEMPLATE_H_
