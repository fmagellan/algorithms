// Copyright 2020 Magellan

#include "basicQueueArrayTemplate.h"

int main() {
    Magellan::BasicQueue<int> queue(10);

    for (int index{}; index < 9; ++index) {
        queue.push_back(index);
    }

    queue.display();
    std::cout << "Pop an item at the front: " << queue.pop_front() << '\n';
    queue.display();

    return (0);
}
