// Copyright 2020 Magellan

// This file implements Dequeue ADT, by using Linked list datastructure.

#ifndef CPP_DEQUEUELINKEDLISTTEMPLATE_H_
#define CPP_DEQUEUELINKEDLISTTEMPLATE_H_

#include <cassert>
#include <iostream>

namespace Magellan {

template <class T>
class Node {
    public:
        T m_data;
        Node *m_prev{ nullptr };
        Node *m_next{ nullptr };
};

template <class T>
class Dequeue {
    private:
        Node<T> *m_front{ nullptr };
        Node<T> *m_back{ nullptr };

    public:
        Dequeue() = default;
        ~Dequeue();

        void push_front(const T &item);
        void push_back(const T &item);
        T pop_front();
        T pop_back();
        bool isEmpty() const;

        friend std::ostream& operator<< (std::ostream &out, const Dequeue &queue) {
            out << "Dequeue: ";
            Node<T> *pNode{ queue.m_front };
            while (pNode) {
                out << pNode->m_data << ' ';
                pNode = pNode->m_next;
            }
            out << '\n';

            return (out);
        }
};

template <class T>
Dequeue<T>::~Dequeue<T> () {
    while (m_front) {
        Node<T> *pNode = m_front;
        m_front = m_front->m_next;
        delete (pNode);
    }
}

template <class T>
void Dequeue<T>::push_front(const T &item) {
    Node<T> *pNode{ new Node<T> };
    pNode->m_data = item;
    pNode->m_next = m_front;
    if (m_front) {
        m_front->m_prev = pNode;
    } else {
        m_back = pNode;
    }
    m_front = pNode;
}

template <class T>
void Dequeue<T>::push_back(const T &item) {
    Node<T> *pNode{ new Node<T> };
    pNode->m_data = item;
    pNode->m_prev = m_back;
    if (m_back) {
        m_back->m_next = pNode;
    } else {
        m_front = pNode;
    }
    m_back = pNode;
}

template <class T>
T Dequeue<T>::pop_front() {
    assert(m_front && "Dequeue is empty. No item to pop.");

    Node<T> *pNode = m_front;
    m_front = m_front->m_next;
    if (m_front) {
        m_front->m_prev = nullptr;
    } else {
        m_back = nullptr;
    }

    T item = pNode->m_data;
    delete (pNode);

    return (item);
}

template <class T>
T Dequeue<T>::pop_back() {
    assert(m_front && "Dequeue is empty. No item to pop.");

    Node<T> *pNode = m_back;
    m_back = m_back->m_prev;
    if (m_back) {
        m_back->m_next = nullptr;
    } else {
        m_front = nullptr;
    }

    T item = pNode->m_data;
    delete (pNode);

    return (item);
}

template <class T>
bool Dequeue<T>::isEmpty() const {
    return (!m_front);
}

};  // namespace Magellan

#endif  // CPP_DEQUEUELINKEDLISTTEMPLATE_H_
