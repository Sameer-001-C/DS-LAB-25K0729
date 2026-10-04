/*

A linear queue becomes full when the rear pointer valuer reaches the last index, eventhough there may be empty spaces at the front of the queue, after dequeuing elements. 
A circular queue solves this problem by using the formula (rear + 1) % N, which allows the rear to wrap around and reuse the empty spaces at the front of the queue after dequeuing elements.

*/

#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    bool isFull()
    {
        return rear == 4;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;
        cout << value << " enqueued" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value = arr[front];
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }

        cout << value << " dequeued" << endl;

        return value;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
