// Copyright 2020 Magellan

// This file implements a circular queue ADT, using an array.

#ifndef CPP_INCLUDE_QUEUEARRAYTEMPLATE_H_
#define CPP_INCLUDE_QUEUEARRAYTEMPLATE_H_

#include <cassert>
#include <iostream>

namespace Magellan {

template <class T>
class Queue {
    private:
        int m_size{};
        int m_front{ -1 };
        int m_back{ -1 };
        T *m_array{};

    public:
        explicit Queue(const int size = 100)
            : m_size{ size }, m_front{ -1 }, m_back{ -1 }, m_array{ nullptr } {
            if (size) {
                m_array = new T[size];
            }
        }

        ~Queue() {
            if (m_size) {
                delete [] m_array;
            }
        }

        void push_back(const T &item);
        T pop_front();
        bool isEmpty() const;
        bool isFull() const;

        friend std::ostream& operator<< (std::ostream &out, const Queue &queue) {
            out << "Queue: ";
            if (queue.isEmpty()) {
                out << '\n';

                return out;
            }

            for (int index{ queue.m_front + 1 }; index != queue.m_back + 1; ++index) {
                index %= queue.m_size;
                out << queue.m_array[index] << ' ';
            }

            out << '\n';

            return out;
        }
};

template <class T>
void Queue<T>::push_back(const T &item) {
    if (isFull()) {
        // if the Queue is full, silently return.
        return;
    }

    ++m_back;
    m_back %= m_size;
    m_array[m_back] = item;
}

template <class T>
T Queue<T>::pop_front() {
    assert((m_front != m_back) && "Queue is empty");

    ++m_front;
    m_front %= m_size;
    return (m_array[m_front]);
}

template <class T>
bool Queue<T>::isEmpty() const {
    return (m_front == m_back);
}

template <class T>
bool Queue<T>::isFull() const {
    return (((m_back + 1) % m_size) == m_front);
}

};  // namespace Magellan

#endif  // CPP_INCLUDE_QUEUEARRAYTEMPLATE_H_
