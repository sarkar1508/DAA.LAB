#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Merge function
void merge(vector<int>& a, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (a[i] < a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= right)
        temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];
}

// Merge Sort
void mergeSort(vector<int>& a, int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}

// Quick Sort
int partitionArray(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionArray(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Function to measure time
long long measureTime(vector<int> a, int choice) {

    auto start = high_resolution_clock::now();

    if (choice == 1)
        bubbleSort(a);

    else if (choice == 2)
        selectionSort(a);

    else if (choice == 3)
        insertionSort(a);

    else if (choice == 4)
        mergeSort(a, 0, a.size() - 1);

    else if (choice == 5)
        quickSort(a, 0, a.size() - 1);

    auto end = high_resolution_clock::now();

    return duration_cast<microseconds>(end - start).count();
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
        cin >> data[i];

    cout << "\n----- SORTING COMPARISON -----\n\n";

    cout << "Algorithm       Time Taken       Average Complexity\n";
    cout << "----------------------------------------------------\n";

    long long t1 = measureTime(data, 1);
    long long t2 = measureTime(data, 2);
    long long t3 = measureTime(data, 3);
    long long t4 = measureTime(data, 4);
    long long t5 = measureTime(data, 5);

    cout << "Bubble Sort     " << t1 << " us          O(n^2)\n";
    cout << "Selection Sort  " << t2 << " us          O(n^2)\n";
    cout << "Insertion Sort  " << t3 << " us          O(n^2)\n";
    cout << "Merge Sort      " << t4 << " us          O(n log n)\n";
    cout << "Quick Sort      " << t5 << " us          O(n log n)\n";

    cout << "\n----- RESULT -----\n";

    long long times[] = {t1, t2, t3, t4, t5};
    string names[] = {
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quick Sort"
    };

    int best = 0;

    for (int i = 1; i < 5; i++) {
        if (times[i] < times[best])
            best = i;
    }

    cout << "Fastest algorithm for this input: "
         << names[best] << endl;

    cout << "\nNote: The fastest algorithm can change depending "
         << "on the input and computer.\n";

    return 0;
}