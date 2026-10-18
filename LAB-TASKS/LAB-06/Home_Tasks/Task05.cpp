
#include <iostream>
using namespace std;



long long factorial(int n, long long accumulator = 1)
{
    if(n <= 1)
    {
        return accumulator;
    }

    return factorial(n - 1, accumulator * n);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if(n < 0 || n > 20)
    {
        cout << "Enter a number between 0 and 20";
    }
    else
    {
        cout << factorial(n);
    }

    return 0;
}
