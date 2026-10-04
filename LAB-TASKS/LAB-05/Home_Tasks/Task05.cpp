#include <iostream>
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

    bool isEmpty()
    {
        return top == -1;
    }
};

class Queue
{
private:
    Stack stackIn;
    Stack stackOut;

public:
    void enqueue(int x)
    {
        stackIn.push(x);
    }

    int dequeue()
    {
        if (stackOut.isEmpty())
        {
            while (!stackIn.isEmpty())
                stackOut.push(stackIn.pop());
        }

        if (stackOut.isEmpty())
            return -1;

        return stackOut.pop();
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << " ";

    q.enqueue(4);

    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << endl;

    return 0;
}
