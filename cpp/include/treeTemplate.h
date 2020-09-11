// Copyright 2020 Magellan
#ifndef CPP_INCLUDE_TREETEMPLATE_H_
#define CPP_INCLUDE_TREETEMPLATE_H_

#include <iostream>

#include "cpp/include/stackLinkedListTemplate.h"

namespace Magellan {

template <class T>
class Tree {
    public:
        template <class NODE = T>
        class Node {
            public:
                NODE m_data;
                Node *m_left{ nullptr };
                Node *m_right{ nullptr };
                ~Node();

            private:
                void freeNode(Node *pNode);
        };

    private:
        Node<T> *m_root{ nullptr };

    public:
        Tree() = default;
        virtual ~Tree();

        Node<T>* getRoot() {
            return (m_root);
        }

        void setRoot(Node<T> *root) {
            m_root = root;
        }

        void populate();
        void populateNode(Node<T> *pParentNode, const bool leftchild);

        void recursiveInOrderDisplay();
        void recursivePreOrderDisplay();
        void recursivePostOrderDisplay();

        void linearInOrderDisplay();
        void linearPreOrderDisplay();

        int height();
        int height(Node<T> *pNode);

    private:
        void recursiveInOrderTraversal(Node<T> *pNode);
        void recursivePreOrderTraversal(Node<T> *pNode);
        void recursivePostOrderTraversal(Node<T> *pNode);
};

template <class T>
template <class NODE>
Tree<T>::Node<NODE>::~Node<NODE> () {
    freeNode(m_left);
    freeNode(m_right);
}

template <class T>
template <class NODE>
void Tree<T>::Node<NODE>::freeNode(Node<NODE> *pNode) {
    if (!m_left) {
        freeNode(m_left);
    }

    if (!m_right) {
        freeNode(m_right);
    }

    free(pNode);
}

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
void Tree<T>::recursiveInOrderDisplay() {
    std::cout << "InOrder display of Tree (recursive method): ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    recursiveInOrderTraversal(m_root);
    std::cout << "\n";
}

template <class T>
void Tree<T>::recursiveInOrderTraversal(Node<T> *pNode) {
    if (!pNode) {
        return;
    }

    recursiveInOrderTraversal(pNode->m_left);
    std::cout << pNode->m_data << ' ';
    recursiveInOrderTraversal(pNode->m_right);
}

template <class T>
void Tree<T>::recursivePreOrderDisplay() {
    std::cout << "PreOrder display of Tree (recursive method): ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    recursivePreOrderTraversal(m_root);
    std::cout << "\n";
}

template <class T>
void Tree<T>::recursivePreOrderTraversal(Node<T> *pNode) {
    if (!pNode) {
        return;
    }

    std::cout << pNode->m_data << ' ';
    recursivePreOrderTraversal(pNode->m_left);
    recursivePreOrderTraversal(pNode->m_right);
}

template <class T>
void Tree<T>::recursivePostOrderDisplay() {
    std::cout << "PostOrder display of Tree (recursive method): ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    recursivePostOrderTraversal(m_root);
    std::cout << "\n";
}

template <class T>
void Tree<T>::recursivePostOrderTraversal(Node<T> *pNode) {
    if (!pNode) {
        return;
    }

    recursivePostOrderTraversal(pNode->m_left);
    recursivePostOrderTraversal(pNode->m_right);
    std::cout << pNode->m_data << ' ';
}

template <class T>
void Tree<T>::linearInOrderDisplay() {
    std::cout << "InOrder display of Tree (linear method): ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    Magellan::Stack<Magellan::Tree<T>::Node<T> *> stackPointers;
    stackPointers.push_back(m_root);
    Magellan::Tree<T>::Node<T> *pNode = m_root->m_left;

    while (pNode || !stackPointers.isEmpty()) {
        if (pNode) {
            stackPointers.push_back(pNode);
            pNode = pNode->m_left;
        } else {
            pNode = stackPointers.pop_back();
            std::cout << pNode->m_data << ' ';
            pNode = pNode->m_right;
        }
    }

    std::cout << '\n';
}

template <class T>
void Tree<T>::linearPreOrderDisplay() {
    std::cout << "PreOrder display of Tree (linear method): ";
    if (!m_root) {
        std::cout << "\n";
        return;
    }

    Magellan::Stack<Magellan::Tree<T>::Node<T> *> stackPointers;
    std::cout << m_root->m_data << ' ';
    stackPointers.push_back(m_root);
    Magellan::Tree<T>::Node<T> *pNode = m_root->m_left;

    while (pNode || !stackPointers.isEmpty()) {
        if (pNode) {
            std::cout << pNode->m_data << ' ';
            stackPointers.push_back(pNode);
            pNode = pNode->m_left;
        } else {
            pNode = stackPointers.pop_back();
            pNode = pNode->m_right;
        }
    }

    std::cout << '\n';
}

template <class T>
int Tree<T>::height() {
    return (height(m_root));
}

template <class T>
int Tree<T>::height(Node<T> *pNode) {
    if (!pNode) {
        return (0);
    }

    int left{ height(pNode->m_left) };
    int right{ height(pNode->m_right) };
    if (left > right) {
        return (left + 1);
    }

    return (right + 1);
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_TREETEMPLATE_H_
