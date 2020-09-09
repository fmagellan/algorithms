// Copyright 2020 Magellan

#include "dequeueLinkedListTemplate.h"

int main() {
    Magellan::Dequeue<int> dequeue;
    dequeue.push_back(11);
    std::cout << dequeue;

    dequeue.push_front(1);
    std::cout << dequeue;

    dequeue.push_front(2);
    std::cout << dequeue;

    return (0);
}
