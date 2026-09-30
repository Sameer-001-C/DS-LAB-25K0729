#include <iostream>
#include <string>
using namespace std;

class CircularQueue
{
private:
    string* arr;
    int front;
    int rear;
    int count;
    int N;

public:
    CircularQueue(int size)
    {
        N = size;
        arr = new string[N];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == N;
    }

    void enqueue(string name)
    {
        if (isFull())
        {
            cout << "Queue is full, cannot add " << name << endl;
            return;
        }

        rear = (rear + 1) % N;
        arr[rear] = name;
        count++;

        cout << name << " added to queue" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Serving " << arr[front] << endl;

        front = (front + 1) % N;
        count--;

        if (count == 0)
        {
            front = 0;
            rear = -1;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Customers waiting: ";

        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % N;
            cout << arr[index];

            if (i < count - 1)
                cout << ", ";
        }

        cout << endl;
    }
};

int main()
{
    int N;
    cout << "Enter maximum number of customers: ";
    cin >> N;
    cin.ignore();

    CircularQueue queue(N);

    int choice;
    string name;

    do
    {
        cout << "\n1. Add Customer" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. View Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter customer name: ";
            getline(cin, name);
            queue.enqueue(name);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            queue.displayQueue();
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    return 0;
}
