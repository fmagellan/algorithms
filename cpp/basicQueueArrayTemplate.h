// Copyright 2020 Magellan

// This file implements a Queue ADT, by using array datastructure.

#ifndef CPP_BASICQUEUEARRAYTEMPLATE_H_
#define CPP_BASICQUEUEARRAYTEMPLATE_H_

#include <cassert>
#include <iostream>

namespace Magellan {

template <class T>
class BasicQueue {
    private:
        int m_front{ -1 };
        int m_back{ -1 };
        int m_size{ 100 };
        T *m_array{};

    public:
        explicit BasicQueue(const int size = 100)
            : m_front{ -1 }, m_back{ -1 }, m_size{ size }, m_array{ nullptr } {
            m_array = new T[size];
        }

        ~BasicQueue() {
            if (!m_array) {
                delete [] m_array;
            }
        }

        void push_back(const T &item);
        T pop_front();
        bool isEmpty();
        bool isFull();
        void display();
};

template <class T>
void BasicQueue<T>::push_back(const T &item) {
    assert((m_back < m_size - 1) && "Queue is full.");

    ++m_back;
    m_array[m_back] = item;
}

template <class T>
T BasicQueue<T>::pop_front() {
    assert((m_front < m_back) && "Queue is empty.");

    ++m_front;
    return (m_array[m_front]);
}

template <class T>
bool BasicQueue<T>::isEmpty() {
    return (m_front == m_back);
}

template <class T>
bool BasicQueue<T>::isFull() {
    return (m_back >= m_size - 1);
}

template <class T>
void BasicQueue<T>::display() {
    std::cout << "Queue: ";
    for (int index{ m_front + 1 }; index <= m_back; ++index) {
        std::cout << m_array[index] << ' ';
    }
    std::cout << '\n';
}

};  // namespace Magellan

#endif  // CPP_BASICQUEUEARRAYTEMPLATE_H_
