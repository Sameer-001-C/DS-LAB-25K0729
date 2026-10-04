#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top < 99)
            arr[++top] = value;
    }

    int pop()
    {
        if (top == -1)
            return -1;

        return arr[top--];
    }

    int size()
    {
        return top + 1;
    }
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool evaluatePostfix(string expression, int& result)
{
    Stack s;

    for (char c : expression)
    {
        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else if (isOperator(c))
        {
            if (s.size() < 2)
                return false;

            int right = s.pop();
            int left = s.pop();

            if (c == '+')
                s.push(left + right);
            else if (c == '-')
                s.push(left - right);
            else if (c == '*')
                s.push(left * right);
            else if (c == '/')
            {
                if (right == 0)
                    return false;

                s.push(left / right);
            }
        }
        else
        {
            return false;
        }
    }

    if (s.size() != 1)
        return false;

    result = s.pop();

    return true;
}

int main()
{
    string expression;
    int result;

    cout << "Enter postfix expression: ";
    getline(cin, expression);

    if (evaluatePostfix(expression, result))
        cout << "Result: " << result << endl;
    else
        cout << "Error: Malformed expression" << endl;

    return 0;
}
