// Copyright 2020 Magellan
#ifndef CPP_INCLUDE_STACKARRAYTEMPLATE_H_
#define CPP_INCLUDE_STACKARRAYTEMPLATE_H_
#include <cassert>

namespace Magellan {

template <class T>
class Stack {
    private:
        T *m_array{};
        int m_size{};
        int m_top{ -1 };

    public:
        explicit Stack(const int size = 0) : m_size{ size }, m_top{ -1 } {
            if (size) {
                m_array = new T[size];
            }
        }

        ~Stack() {
            if (m_array) {
                delete [] m_array;
            }
        }

        T pop();
        void push(const T &item);
        T back() const;
        bool isEmpty() const;
};

template <class T>
T Stack<T>::pop() {
    assert((m_top > -1) && "Stack is empty. Cannot pop anymore.");
    T item { m_array[m_top--] };

    return (item);
}

template <class T>
void Stack<T>::push(const T &item) {
    if (m_top > m_size - 1) {
        // Do not assert, but return silently.
        return;
    }

    m_array[++m_top] = item;
}

template <class T>
T Stack<T>::back() const {
    assert((m_top > -1) && "Stack is empty. There are no elements.");
    return (m_array[m_top]);
}

template <class T>
bool Stack<T>::isEmpty() const {
    if (m_top < 0) {
        return (true);
    }

    return false;
}

}  // namespace Magellan

#endif  // CPP_INCLUDE_STACKARRAYTEMPLATE_H_
