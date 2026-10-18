#include <iostream>
using namespace std;

int power(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    
    if(n == 1)
    {
        return x;
    }

    return x * power(x, n-1);
}



int fasterPower(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }

    if(n == 1)
    {
        return x;
    }

    int temp = fasterPower(x, n/2);

    temp *= temp;

    if(n % 2 == 1)
    {
        temp *= x;
    }

    return temp;
}



int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    int pow;
    cout << "Enter power: ";
    cin >> pow;

    int result = fasterPower(num, pow);

    cout << "Result: " << result << endl;


    return 0;
}