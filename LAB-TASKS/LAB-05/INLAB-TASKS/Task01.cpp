#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    string data[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(string task)
    {
        if (top < 99)
        {
            data[++top] = task;
            cout << "\"" << task << "\" pushed into stack" << endl;
        }
    }

    string pop()
    {
        if (!isEmpty())
        {
            return data[top--];
        }

        return "";
    }

    string peek()
    {
        if (!isEmpty())
        {
            return data[top];
        }

        return "";
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No pending tasks" << endl;
            return;
        }

        cout << "Pending tasks (top to bottom):" << endl;

        for (int i = top; i >= 0; i--)
        {
            cout << data[i] << endl;
        }
    }

    void undoLastTask()
    {
        if (isEmpty())
        {
            cout << "No task to remove" << endl;
            return;
        }

        string task = pop();
        cout << "Removed: " << task << endl;
    }

    void search(string task)
    {
        int above = 0;

        for (int i = top; i >= 0; i--)
        {
            if (data[i] == task)
            {
                cout << "Task found. " << above << " task(s) above it." << endl;
                return;
            }

            above++;
        }

        cout << "Task not found" << endl;
    }
};

int main()
{
    Stack tasks;
    int choice;
    string task;

    do
    {
        cout << "\n1. Add Task" << endl;
        cout << "2. Remove Last Task" << endl;
        cout << "3. View All Tasks" << endl;
        cout << "4. Search Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter task: ";
            getline(cin, task);
            tasks.push(task);
            break;

        case 2:
            tasks.undoLastTask();
            break;

        case 3:
            tasks.display();
            break;

        case 4:
            cout << "Enter task to search: ";
            getline(cin, task);
            tasks.search(task);
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}
