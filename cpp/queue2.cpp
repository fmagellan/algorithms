// Copyright 2020 Magellan

#include "queueArrayTemplate.h"

int main() {
    Magellan::Queue<int> queue(10);

    queue.push_back(0);
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
    queue.push_back(4);
    queue.push_back(5);
    queue.push_back(6);
    queue.push_back(7);
    queue.push_back(8);

    std::cout << queue;

    queue.pop_front();
    std::cout << queue;

    queue.push_back(9);
    std::cout << queue;

    queue.push_back(10);
    std::cout << queue;

    queue.push_back(11);
    std::cout << queue;

    queue.push_back(12);
    std::cout << queue;

    queue.pop_front();
    std::cout << queue;

    queue.pop_front();
    std::cout << queue;

    queue.push_back(13);
    std::cout << queue;

    return (0);
}
