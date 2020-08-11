// Copyright 2020 Magellan
#include <algorithm>
#include <iostream>

typedef struct {
    char id{};
    int deadline{};
    int profit{};
} Job;

typedef struct {
    int id{};
    char jobId{};
    bool is_full{};
} Slot;

bool jobProfitComparator(const Job &j1, const Job &j2) {
    return (j1.profit > j2.profit);
}

int main() {
    Job jobs[] {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    const int numJobs{ static_cast<int>(sizeof(jobs) / sizeof(Job)) };
    Slot slots[numJobs]{};

    std::cout << "Number of jobs: " << numJobs << '\n';
    std::sort(jobs, jobs + numJobs, jobProfitComparator);

    for (auto &job : jobs) {
        std::cout << "Profit of Job[" << job.id << "]: " << job.profit << '\n';
    }

    for (int jobIndex{}; jobIndex < numJobs; ++jobIndex) {
        for (int slotIndex{ jobs[jobIndex].deadline - 1 }; slotIndex >= 0; --slotIndex) {
            if (slots[slotIndex].is_full) {
                continue;
            }

            slots[slotIndex].jobId = jobs[jobIndex].id;
            slots[slotIndex].is_full = true;
            break;
        }
    }

    for (auto &slot : slots) {
        std::cout << "Slot[" << slot.jobId << "]\n";
    }

    Slot resultSlots[numJobs]{};
    for (int slotIndex{}, resultSlotIndex{}; slotIndex < numJobs; ++slotIndex) {
        if (!slots[slotIndex].jobId) {
            continue;
        }

        resultSlots[resultSlotIndex].jobId = slots[slotIndex].jobId;
        resultSlots[resultSlotIndex].is_full = true;
        resultSlotIndex++;
    }

    for (auto &slot : resultSlots) {
        if (!(slot.jobId)) {
            break;
        }
        std::cout << "ResultSlot[" << slot.jobId << "]\n";
    }

    return (0);
}
