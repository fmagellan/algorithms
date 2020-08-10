// Copyright 2020 Magellan
#include <iostream>

#include "input_utilities.h"

int knapSack(std::vector<int> &values, std::vector<int> &weights,
        const int numberOfItems, const int maxTotalWeight) {
    if ((numberOfItems == 0) || (maxTotalWeight == 0)) {
        return (0);
    }

    if (weights[numberOfItems - 1] > maxTotalWeight) {
        return (knapSack(values, weights, numberOfItems - 1, maxTotalWeight));
    }

    else {
        int weightWith_N = values[numberOfItems - 1] + knapSack(values, weights,
                numberOfItems - 1, maxTotalWeight - weights[numberOfItems - 1]);

        int weightWithout_N = knapSack(values, weights, numberOfItems - 1, maxTotalWeight);

        return std::max(weightWith_N, weightWithout_N);
    }
}

int main() {
    std::vector<int> values;
    std::cout << "Enter the values.\n";
    getInputVector(values);

    std::vector<int> weights;
    std::cout << "Enter the weights.\n";
    getInputVector(weights);

    int size{ static_cast<int> (values.size()) };
    if (size != static_cast<int> (weights.size())) {
        std::cout << "The sizes of the values-vector and weights-vector should be same.\n";
        return (0);
    }

    int maxTotalWeight{};
    std::cout << "Enter the Max total weight constraint:";
    std::cin >> maxTotalWeight;

    std::cout << knapSack(values, weights, size, maxTotalWeight) << '\n';

    return (0);
}
