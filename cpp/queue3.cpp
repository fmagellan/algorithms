// Copyright 2020 Magellan

#include "cpp/queueLinkedListTemplate.h"

int main() {
    Magellan::Queue<int> queue;
    queue.push_back(10);
    queue.push_back(11);
    queue.push_back(12);
    std::cout << queue;

    queue.push_back(13);
    std::cout << "Popping: " << queue.pop_front() << '\n';

    std::cout << queue;

    return (0);;
}
