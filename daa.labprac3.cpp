#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Function to maintain heap property
void adjustHeap(vector<int>& arr, int n, int index, int type)
{
    int selected = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Max Heap
    if (type == 1)
    {
        if (left < n && arr[left] > arr[selected])
            selected = left;

        if (right < n && arr[right] > arr[selected])
            selected = right;
    }

    // Min Heap
    else
    {
        if (left < n && arr[left] < arr[selected])
            selected = left;

        if (right < n && arr[right] < arr[selected])
            selected = right;
    }

    // If selected value is different from current index
    if (selected != index)
    {
        swap(arr[index], arr[selected]);

        // Fix the affected subtree
        adjustHeap(arr, n, selected, type);
    }
}

// Heap Sort function
void performHeapSort(vector<int>& arr, int type)
{
    int n = arr.size();

    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        adjustHeap(arr, n, i, type);
    }

    // Remove elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        adjustHeap(arr, i, 0, type);
    }

    // Min Heap gives descending order
    // Reverse it to obtain ascending order
    if (type == 2)
    {
        reverse(arr.begin(), arr.end());
    }
}

// Display execution time
void showTime(string algorithm, long long time)
{
    cout << "\n========== " << algorithm << " ==========\n";

    cout << "Nanoseconds  : "
         << time << " ns\n";

    cout << "Microseconds : "
         << time / 1000.0 << " us\n";

    cout << "Milliseconds : "
         << time / 1000000.0 << " ms\n";
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Create original array
    vector<int> original(n);

    // Initialize random number generator
    srand(time(0));

    // Generate random values
    for (int i = 0; i < n; i++)
    {
        original[i] = rand() % 100000;
    }

    // Create two identical arrays
    vector<int> maxArray = original;
    vector<int> minArray = original;

    // ---------------- MAX HEAP SORT ----------------

    auto startMax = high_resolution_clock::now();

    performHeapSort(maxArray, 1);

    auto endMax = high_resolution_clock::now();

    // ---------------- MIN HEAP SORT ----------------

    auto startMin = high_resolution_clock::now();

    performHeapSort(minArray, 2);

    auto endMin = high_resolution_clock::now();

    // Calculate execution time
    long long maxTime =
        duration_cast<nanoseconds>(
            endMax - startMax
        ).count();

    long long minTime =
        duration_cast<nanoseconds>(
            endMin - startMin
        ).count();

    // Display results
    showTime("MAX HEAP SORT", maxTime);
    showTime("MIN HEAP SORT", minTime);

    return 0;
}