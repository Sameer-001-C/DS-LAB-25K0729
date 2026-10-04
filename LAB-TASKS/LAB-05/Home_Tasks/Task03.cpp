#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char c)
    {
        if (top < 99)
            arr[++top] = c;
    }

    char pop()
    {
        if (top == -1)
            return '\0';

        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool matches(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isBalanced(string expression)
{
    Stack s;

    for (char c : expression)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.isEmpty())
                return false;

            char opening = s.pop();

            if (!matches(opening, c))
                return false;
        }
    }

    return s.isEmpty();
}

int main()
{
    string expression;

    cout << "Enter expression: ";
    getline(cin, expression);

    if (isBalanced(expression))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
