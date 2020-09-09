// Copyright 2020 Magellan

// This file implements a Queue ADT by using a Linked list datastructure.

#ifndef CPP_INCLUDE_QUEUELINKEDLISTTEMPLATE_H_
#define CPP_INCLUDE_QUEUELINKEDLISTTEMPLATE_H_

#include <cassert>
#include <iostream>

namespace Magellan {

template <class T>
class Node {
    public:
        T m_data;
        Node *m_next{};
};

template <class T>
class Queue {
    private:
        Node<T> *m_front{ nullptr };
        Node<T> *m_back{ nullptr };

    public:
        Queue() = default;

        ~Queue() {
            Node<T> *pNode{ nullptr };
            while (m_front) {
                pNode = m_front;
                m_front = m_front->m_next;
                delete (pNode);
            }
        }

        void push_back(const T &item);
        T pop_front();
        bool isEmpty() const;

        friend std::ostream& operator<< (std::ostream &out, const Queue &queue) {
            out << "Queue: ";
            Node<T> *pNode{ queue.m_front };
            while (pNode) {
                std::cout << pNode->m_data << ' ';
                pNode = pNode->m_next;
            }
            out << '\n';

            return (out);
        }
};

template <class T>
void Queue<T>::push_back(const T &item) {
    Node<T> *pNode{  new Node<T> };
    pNode->m_data = item;
    pNode->m_next = nullptr;

    if (!m_back) {
        m_front = m_back = pNode;
        return;
    }

    m_back->m_next = pNode;
    m_back = pNode;
}

template <class T>
T Queue<T>::pop_front() {
    assert(m_front && "Queue is empty. Cannot pop any element.");

    T item = m_front->m_data;
    m_front = m_front->m_next;

    return (item);
}

template <class T>
bool Queue<T>::isEmpty() const {
    return (!m_front);
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_QUEUELINKEDLISTTEMPLATE_H_
