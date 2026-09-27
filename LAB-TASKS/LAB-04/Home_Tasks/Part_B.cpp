#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node* head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;

        do
        {
            cout << current->data;

            current = current->next;

            if (current != head)
                cout << " -> ";
        }
        while (current != head);

        cout << endl;
    }

    void append(int val)
    {
        Node* newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* current = head;

        while (current->next != head)
            current = current->next;

        current->next = newNode;
        newNode->next = head;
    }

    void insert(int pos, int val)
    {
        if (pos < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0)
        {
            Node* newNode = new Node(val);

            if (head == nullptr)
            {
                head = newNode;
                newNode->next = head;
                return;
            }

            Node* last = head;

            while (last->next != head)
                last = last->next;

            newNode->next = head;
            last->next = newNode;
            head = newNode;

            return;
        }

        if (head == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* current = head;
        int index = 0;

        while (index < pos - 1 && current->next != head)
        {
            current = current->next;
            index++;
        }

        if (index != pos - 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteValue(int val)
    {
        if (head == nullptr)
        {
            cout << "Value not found" << endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        do
        {
            if (current->data == val)
                break;

            previous = current;
            current = current->next;
        }
        while (current != head);

        if (current->data != val)
        {
            cout << "Value not found" << endl;
            return;
        }

        if (current == head)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
                return;
            }

            Node* last = head;

            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;

            delete current;
            return;
        }

        previous->next = current->next;
        delete current;
    }

    bool search(int key)
    {
        if (head == nullptr)
            return false;

        Node* current = head;

        do
        {
            if (current->data == key)
                return true;

            current = current->next;
        }
        while (current != head);

        return false;
    }
};

int main()
{
    CircularLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Initial list: ";
    list.display();

    list.insert(0, 5);
    list.insert(2, 15);
    list.insert(5, 40);

    cout << "After insertions: ";
    list.display();

    cout << "Search 20: ";

    if (list.search(20))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    cout << "Search 100: ";

    if (list.search(100))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    list.deleteValue(5);

    cout << "After deleting head: ";
    list.display();

    list.deleteValue(30);

    cout << "After deleting 30: ";
    list.display();

    list.deleteValue(100);

    return 0;
}
