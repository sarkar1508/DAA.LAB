#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Function for Linear Search
// Checks each element one by one
int linearSearch(const vector<int>& arr, int key)
{
    // Start searching from the first element
    for (int i = 0; i < arr.size(); i++)
    {
        // Check if current element matches the key
        if (arr[i] == key)
            return i;  // Return index if found
    }

    // Return -1 if element is not found
    return -1;
}

// Function for Binary Search
// Works only on a sorted array
int binarySearch(const vector<int>& arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;

    // Continue searching while the range is valid
    while (left <= right)
    {
        // Find the middle element
        int middle = (left + right) / 2;

        // Check if middle element is the key
        if (arr[middle] == key)
            return middle;

        // If key is greater, search in the right half
        if (arr[middle] < key)
            left = middle + 1;

        // Otherwise, search in the left half
        else
            right = middle - 1;
    }

    // Return -1 if element is not found
    return -1;
}

int main()
{
    // Number of elements in the array
    int n = 100000;

    // Create an empty vector
    vector<int> numbers;

    // Create a sorted array from 1 to 100000
    for (int i = 1; i <= n; i++)
    {
        numbers.push_back(i);
    }

    // Variable to store the element to search
    int key;

    cout << "Enter element to search: ";
    cin >> key;


    // ==================================================
    //              LINEAR SEARCH
    // ==================================================

    // Start the timer
    auto startLinear = high_resolution_clock::now();

    // Perform Linear Search
    int linearResult = linearSearch(numbers, key);

    // Stop the timer
    auto endLinear = high_resolution_clock::now();

    // Calculate execution time in microseconds
    auto linearTime =
        duration_cast<microseconds>(endLinear - startLinear).count();

    cout << "\n===== Linear Search =====\n";

    // Display search result
    if (linearResult != -1)
        cout << "Element found at index: " << linearResult << endl;
    else
        cout << "Element not found" << endl;

    // Display execution time
    cout << "Time Taken: "
         << linearTime << " microseconds\n";


    // ==================================================
    //              BINARY SEARCH
    // ==================================================

    // Start the timer
    auto startBinary = high_resolution_clock::now();

    // Perform Binary Search
    int binaryResult = binarySearch(numbers, key);

    // Stop the timer
    auto endBinary = high_resolution_clock::now();

    // Calculate execution time
    auto binaryTime =
        duration_cast<microseconds>(endBinary - startBinary).count();

    cout << "\n===== Binary Search =====\n";

    // Display search result
    if (binaryResult != -1)
        cout << "Element found at index: " << binaryResult << endl;
    else
        cout << "Element not found" << endl;

    // Display execution time
    cout << "Time Taken: "
         << binaryTime << " microseconds\n";


    // ==================================================
    //              COMPARISON
    // ==================================================

    cout << "\n===== Comparison =====\n";

    // Display theoretical time complexities
    cout << "Linear Search : O(n)" << endl;
    cout << "Binary Search : O(log n)" << endl;

    // Compare actual execution times
    if (linearTime < binaryTime)
        cout << "Linear Search was faster for this test." << endl;

    else if (binaryTime < linearTime)
        cout << "Binary Search was faster for this test." << endl;

    else
        cout << "Both took approximately the same time." << endl;

    return 0;
}