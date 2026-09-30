#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char data[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char value)
    {
        data[++top] = value;
    }

    char pop()
    {
        return data[top--];
    }

    char peek()
    {
        return data[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool isBalanced(string expression)
{
    Stack s;

    for (char ch : expression)
    {
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            if (s.isEmpty())
                return false;

            s.pop();
        }
    }

    return s.isEmpty();
}

string infixToPostfix(string expression)
{
    Stack s;
    string postfix;

    for (char ch : expression)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }

            s.pop();
        }
        else if (isOperator(ch))
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(ch) ||
                   (precedence(s.peek()) == precedence(ch) && ch != '^')))
            {
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}

int main()
{
    string expression;

    cout << "Input: ";
    cin >> expression;

    if (!isBalanced(expression))
    {
        cout << "Invalid Expression" << endl;
    }
    else
    {
        cout << "Output: " << infixToPostfix(expression) << endl;
    }

    return 0;
}
