#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial
unsigned long long iterativeFactorial(int num)
{
    unsigned long long fact = 1;

    while(num > 1)
    {
        fact = fact * num;
        num--;
    }

    return fact;
}

// Recursive Factorial
unsigned long long recursiveFactorial(int num)
{
    if(num == 0 || num == 1)
        return 1;

    return num * recursiveFactorial(num - 1);
}

int main()
{
    int n;

    cout << "Enter a number : ";
    cin >> n;

    if(n < 0)
    {
        cout << "Factorial is not defined for negative numbers.";
        return 0;
    }

    // Time for Iterative Method
    auto start1 = high_resolution_clock::now();
    unsigned long long ans1 = iterativeFactorial(n);
    auto stop1 = high_resolution_clock::now();

    // Time for Recursive Method
    auto start2 = high_resolution_clock::now();
    unsigned long long ans2 = recursiveFactorial(n);
    auto stop2 = high_resolution_clock::now();

    auto time1 = duration_cast<nanoseconds>(stop1 - start1);
    auto time2 = duration_cast<nanoseconds>(stop2 - start2);

    cout << "\nFactorial using Iterative Method = " << ans1 << endl;
    cout << "Execution Time = " << time1.count() << " ns" << endl;

    cout << "\nFactorial using Recursive Method = " << ans2 << endl;
    cout << "Execution Time = " << time2.count() << " ns" << endl;

    return 0;
}