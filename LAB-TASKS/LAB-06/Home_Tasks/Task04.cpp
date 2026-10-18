
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s, int left, int right)
{
    if(left >= right)
    {
        return true;
    }

    if(s[left] != s[right])
    {
        return false;
    }

    return isPalindrome(s, left + 1, right - 1);
}



int main()
{
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    if(isPalindrome(s, 0, s.length() - 1))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not a palindrome";
    }

    return 0;
}
