// Copyright 2020 Magellan

// This file implements a Stack ADT by using linked list datastructure.

#ifndef CPP_INCLUDE_STACKLINKEDLISTTEMPLATE_H_
#define CPP_INCLUDE_STACKLINKEDLISTTEMPLATE_H_
#include <cassert>

namespace Magellan {

template <class T>
class Node {
    public:
        T m_data;
        Node *m_next{ nullptr };
};

template <class T>
class Stack {
    private:
        Node<T> *m_top{ nullptr };

    public:
        Stack() : m_top{ nullptr } {
        }

        ~Stack() {
            while (m_top) {
                Node<T> *pNode = m_top;
                m_top = m_top->m_next;
                delete pNode;
            }
        }

        void push_back(const T &item);
        T pop_back();
        bool isEmpty();
        void display();
};

template <class T>
void Stack<T>::push_back(const T &item) {
    Node<T> *pNode = new Node<T>;
    pNode->m_data = item;

    if (!m_top) {
        m_top = pNode;
        return;
    }

    pNode->m_next = m_top;
    m_top = pNode;
}

template <class T>
T Stack<T>::pop_back() {
    assert(m_top && "Stack is empty. Cannot pop_back.");

    Node<T> *pNode = m_top;
    m_top = m_top->m_next;
    return (pNode->m_data);
}

template <class T>
bool Stack<T>::isEmpty() {
    return (m_top == nullptr);
}

template <class T>
void Stack<T>::display() {
    Node<T> *pNode = m_top;
    std::cout << "Stack: ";
    while (pNode) {
        std::cout << pNode->m_data << ' ';
        pNode = pNode->m_next;
    }
    std::cout << '\n';
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_STACKLINKEDLISTTEMPLATE_H_
