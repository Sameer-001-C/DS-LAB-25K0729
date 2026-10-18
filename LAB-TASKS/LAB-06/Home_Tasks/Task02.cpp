#include <iostream>
using namespace std;



string Reverses(string myString)
{

    if(myString.length() <= 1)
    {
        return myString;
    }
    
    string copied;

    for(int i = 1; i < myString.length(); i++)
    {
        copied += myString[i];
    }

    return Reverses(copied) + myString[0];
}

int main()
{
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string output = Reverses(input);

    cout << output;

    return 0;
}