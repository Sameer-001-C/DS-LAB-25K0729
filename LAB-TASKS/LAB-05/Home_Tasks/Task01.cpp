#include <iostream>
#include <string>
#include <algorithm>
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

    char peek()
    {
        if (top == -1)
            return '\0';

        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPrecedence(char c)
{
    if (c == '^')
        return 3;

    if (c == '*' || c == '/')
        return 2;

    if (c == '+' || c == '-')
        return 1;

    return 0;
}

bool isBalanced(string expression)
{
    Stack s;

    for (char c : expression)
    {
        if (c == '(')
            s.push(c);

        else if (c == ')')
        {
            if (s.isEmpty())
                return false;

            s.pop();
        }
    }

    return s.isEmpty();
}

string infixToPrefix(string expression)
{
    reverse(expression.begin(), expression.end());

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
            expression[i] = ')';
        else if (expression[i] == ')')
            expression[i] = '(';
    }

    Stack s;
    string result;

    for (char c : expression)
    {
        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                result += s.pop();

            if (!s.isEmpty())
                s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   getPrecedence(s.peek()) > getPrecedence(c))
            {
                result += s.pop();
            }

            s.push(c);
        }
    }

    while (!s.isEmpty())
        result += s.pop();

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string expression;

    cout << "Enter infix expression: ";
    cin >> expression;

    if (!isBalanced(expression))
    {
        cout << "Error: Unbalanced parentheses" << endl;
        return 0;
    }

    cout << "Prefix: " << infixToPrefix(expression) << endl;

    return 0;
}
