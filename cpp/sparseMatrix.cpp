// Copyright 2020 Magellan
#include <cassert>
#include <iomanip>
#include <iostream>

class Entry {
    public:
        int m_column{};
        int m_value{};
        Entry *m_next{};

        explicit Entry(const int column = -1, const int value = 0)
            : m_column{ column }, m_value{ value } {
        }
};

class SparseMatrix {
    private:
        int m_numberOfRows{};
        int m_numberOfColumns{};
        Entry **m_row;

    public:
        SparseMatrix() = default;

        ~SparseMatrix() {
            delete [] m_row;
        }

        int getNumberOfRows() const {
            return (m_numberOfRows);
        }

        void setNumberOfRows(const int rows) {
            m_numberOfRows = rows;
            m_row = new Entry* [rows];
        }

        int getNumberOfColumns() const {
            return (m_numberOfColumns);
        }

        void setNumberOfColumns(const int columns) {
            m_numberOfColumns = columns;
        }

        void addEntry(const int row, const int column, const int value);
        void input();
        void display();
};

void SparseMatrix::addEntry(const int row, const int column, const int value) {
    assert(row < m_numberOfRows && "Invalid number of rows");

    Entry *newEntry = new Entry(column, value);
    Entry *lastEntry = m_row[row], *prev{};
    if (!lastEntry) {
        m_row[row] = newEntry;
        return;
    }

    if (column < lastEntry->m_column) {
        m_row[row] = newEntry;
        newEntry->m_next = lastEntry;
        return;
    }

    while (lastEntry && column > lastEntry->m_column) {
        prev = lastEntry;
        lastEntry = lastEntry->m_next;
    }

    prev->m_next = newEntry;
}

void SparseMatrix::input() {
/*    std::cout << "Enter the number of rows: ";
    std::cin >> m_numberOfRows;
    std::cout << "Enter the number of columns: ";
    std::cin >> m_numberOfColumns; */

    while(true) {
        std::cout << "Do you want to enter an entry ? (y/n): ";
        char response{};
        std::cin >> response;
        if (response != 'y') {
            return;
        }

        int row{}, column{}, value{};
        std::cout << "Enter row number: ";
        std::cin >> row;

        std::cout << "Enter column number: ";
        std::cin >> column;

        std::cout << "Enter the value: ";
        std::cin >> value;

        addEntry(row, column, value);
    }
}

void SparseMatrix::display() {
    std::cout << "Displaying the matrix.\n";
    for (int rowIndex{}; rowIndex < m_numberOfRows; ++rowIndex) {
        Entry *entry{ m_row[rowIndex] };
        int columnIndex{};
        if (!entry) {
            // All elements in the row are zero. print the same.
            for (columnIndex = 0; columnIndex < m_numberOfColumns; ++columnIndex) {
                std::cout << std::setw(10) << 0;
            }
            std::cout << '\n';
            continue;
        }

        while (entry) {
            if (columnIndex != entry->m_column) {
                while (columnIndex < entry->m_column) {
                    std::cout << std::setw(10) << 0;
                    ++columnIndex;
                }
            }

            std::cout << std::setw(10) << entry->m_value;
            entry = entry->m_next;
            ++columnIndex;
        }

        while (columnIndex < m_numberOfColumns) {
            std::cout << std::setw(10) << 0;
            ++columnIndex;
        }

        std::cout << '\n';
    }
}

int main() {
    SparseMatrix matrix;
    matrix.setNumberOfRows(5);
    matrix.setNumberOfColumns(5);
    matrix.display();
    matrix.input();
    matrix.display();

    return (0);
}
