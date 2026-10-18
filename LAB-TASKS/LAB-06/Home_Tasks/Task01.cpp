#include <iostream>
using namespace std;



int SumDigits(int num)
{
    int sum = 0;

    if(num/10 != 0)
    {
        sum += SumDigits(num / 10);
    }

    sum += num % 10;
    return sum;
}


int main()
{
    int myNum;

    cout << "Enter your Number: ";
    cin >> myNum;

    int mySum = SumDigits(myNum);

    cout << "Sum of Digits: " << mySum << endl;

    return 0;
}
