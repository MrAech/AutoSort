#include <iostream>
#include <vector>
#include <string>
#include "SortingManager.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "BucketSort.h"

// Helper function to print CSV data
void printData(const std::vector<std::vector<std::string>>& data) {
    for (const auto& row : data) {
        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

// Helper function to convert string to appropriate data type
DataType detectDataType(const std::vector<std::string>& columnData) {
    bool isDouble = false;
    bool isFloat = false;
    bool isInt = true;

    for (const auto& value : columnData) {
        try {
            double num = std::stod(value);
            if (value.find('.') != std::string::npos) {
                isDouble = true;
                isInt = false;
            }
        }
        catch (...) {
            isInt = false;
        }
    }

    if (isDouble) return DataType::DOUBLE;
    if (isFloat) return DataType::FLOAT;
    if (isInt) return DataType::INT;
    return DataType::STRING;
}

// Function to test sorting for each method and data type
void testSortingMethods(const std::vector<std::vector<std::string>>& csvData) {
    SortingManager sortingManager;
    std::vector<DataType> dataTypes;

    // Determine data types for each column
    for (size_t i = 0; i < csvData[0].size(); ++i) {
        std::vector<std::string> columnData;
        for (const auto& row : csvData) {
            columnData.push_back(row[i]);
        }
        dataTypes.push_back(detectDataType(columnData));
    }

    // Test each sorting method for each column
    for (size_t columnIndex = 0; columnIndex < csvData[0].size(); ++columnIndex) {
        std::cout << "Testing column " << columnIndex << " of type "
            << (dataTypes[columnIndex] == DataType::STRING ? "STRING" :
                dataTypes[columnIndex] == DataType::INT ? "INT" :
                dataTypes[columnIndex] == DataType::FLOAT ? "FLOAT" : "DOUBLE")
            << ":\n";

        // Create a copy of the data for sorting
        std::vector<std::vector<std::string>> dataCopy = csvData;

        // Test Bubble Sort
        std::cout << "Bubble Sort:\n";
        sortingManager.sort(dataCopy, columnIndex, dataTypes[columnIndex]);
        printData(dataCopy);

        // Repeat for other sorting methods
        dataCopy = csvData;  // Reset dataCopy for the next sort

        std::cout << "Selection Sort:\n";
        sortingManager.sort(dataCopy, columnIndex, dataTypes[columnIndex]);
        printData(dataCopy);

        dataCopy = csvData;
        std::cout << "Insertion Sort:\n";
        sortingManager.sort(dataCopy, columnIndex, dataTypes[columnIndex]);
        printData(dataCopy);

        dataCopy = csvData;
        std::cout << "Quick Sort:\n";
        sortingManager.sort(dataCopy, columnIndex, dataTypes[columnIndex]);
        printData(dataCopy);

        dataCopy = csvData;
        std::cout << "Merge Sort:\n";
        sortingManager.sort(dataCopy, columnIndex, dataTypes[columnIndex]);
        printData(dataCopy);

        dataCopy = csvData;
        std::cout << "Radix Sort:\n";
        sortingManager.sort(dataCopy, columnIndex, dataTypes[columnIndex]);
        printData(dataCopy);

        dataCopy = csvData;
        std::cout << "Bucket Sort:\n";
        sortingManager.sort(dataCopy, columnIndex, dataTypes[columnIndex]);
        printData(dataCopy);
    }
}

int main() {
    // Mock CSV data
    std::vector<std::vector<std::string>> csvData = {
        {"John", "25", "3.5", "1000"},
        {"Alice", "22", "3.9", "900"},
        {"Bob", "30", "2.8", "1100"},
        {"Eve", "28", "3.1", "1050"}
    };

    std::cout << "Original Data:\n";
    printData(csvData);

    // Test all sorting methods on all columns
    testSortingMethods(csvData);

    return 0;
}
