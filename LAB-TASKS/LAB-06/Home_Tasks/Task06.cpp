
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

long long fib(int n)
{
    if(n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

long long fibMemo(int n, long long memo[])
{
    if(n <= 1)
    {
        return n;
    }

    if(memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);

    return memo[n];
}

int main()
{
    int n = 40;

    auto start1 = high_resolution_clock::now();
    long long result1 = fib(n);
    auto end1 = high_resolution_clock::now();

    long long memo[41];

    for(int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    auto start2 = high_resolution_clock::now();
    long long result2 = fibMemo(n, memo);
    auto end2 = high_resolution_clock::now();

    auto time1 = duration_cast<microseconds>(end1 - start1).count();
    auto time2 = duration_cast<microseconds>(end2 - start2).count();

    cout << "Ordinary Fibonacci: " << result1 << endl;
    cout << "Ordinary time: " << time1 << " microseconds" << endl;

    cout << "Memoized Fibonacci: " << result2 << endl;
    cout << "Memoized time: " << time2 << " microseconds" << endl;

    return 0;
}
