// Copyright 2020 Magellan
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main() {
    // 1. Read an input vector in a single line, which is in ascending order.
    // 2. Print the vector.
    // 3. Verify if it is in ascending order, else return error.
    // 4. Ask for an input number, from the user.
    // 5. Search for the input number in the linear order, and print the index.
    // 6. Search for the input number in the binary order, and print the index.
    // 7. If you finished all the above steps, you earned a shawarma roll !
    //    Too bad, you can't go out to eat, cause of the corona lockdown. :(

    std::vector<int> ascVector;
    // 1. Read an input vector in a single line, which is in ascending order.
    std::cout << "Enter the vector:\n";
    std::string line{};
    std::getline(std::cin, line);
    std::stringstream stream{ line };
    int insElement{};
    while (stream >> insElement) {
        ascVector.push_back(insElement);
    }

    // 2. Print the vector.
    std::cout << "\nYou have entered the below vector.\n";
    for (const auto &itrElement : ascVector) {
        std::cout << itrElement << ' ';
    }
    std::cout << '\n';

    // 3. Verify if it is in ascending order, else return error.
    int maxElement{};
    for (const auto &itrElement : ascVector) {
        if (maxElement > itrElement) {
            std::cout << "The array is not in ascending order.\n";
            return (0);
        }

        maxElement = itrElement;
    }

    // 4. Ask for an input number, from the user.
    int elementToSearch{};
    std::cout << "\nDo you want to search a number in the array? Y/N: ";
    char response{};
    while ((std::cin >> response) && (response == 'Y')) {
        std::cout << "Enter a number, that will be used to search in the array: ";
        std::cin >> elementToSearch;

        // 5. Search for the input number in the linear order, and print the index.
        {
            bool isFound{};
            int indexFound{};
            for (int index{}; index < ascVector.size(); ++index) {
                if (elementToSearch == ascVector[index])  {
                    isFound = true;
                    indexFound = index;
                    break;
                }

                if (elementToSearch > ascVector[index]) {
                    continue;
                }

                if (elementToSearch < ascVector[index]) {
                    break;
                }
            }

            if (isFound) {
                std::cout << "Used Linear search. The element is found. The index is: " << indexFound << '\n';
            } else {
                std::cout << "Used Linear search. The element is NOT found.\n";
            }
        }

        // 6. Search for the input number in the binary order, and print the index.
        {
            bool isFound{};
            int lowIndex{ 0 }, highIndex{ static_cast<int>(ascVector.size()) - 1 };
            int midIndex{ (lowIndex + highIndex) / 2 };
            while (lowIndex <= highIndex) {
                if (elementToSearch == ascVector[midIndex]) {
                    isFound = true;
                    break;
                }

                if (lowIndex == highIndex) {
                    break;
                }

                if (elementToSearch < ascVector[midIndex]) {
                    highIndex = midIndex - 1;
                    midIndex = (lowIndex + highIndex) / 2;
                    continue;
                }

                if (elementToSearch > ascVector[midIndex]) {
                    lowIndex = midIndex + 1;
                    midIndex = (lowIndex + highIndex) / 2;
                    continue;
                }
            }

            if (isFound) {
                std::cout << "Used Binary search. The element is found. The index is: " << midIndex << '\n';
            } else {
                std::cout << "Used Binary search. The element is NOT found.\n";
            }
        }

        std::cout << "\nDo you want to search a number in the array, again? Y/N: ";
    }

    return (0);
}
