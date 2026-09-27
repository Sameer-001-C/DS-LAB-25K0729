#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void displayForward()
    {
        Node* current = head;

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
                cout << " <-> ";

            current = current->next;
        }

        cout << endl;
    }

    void displayBackward()
    {
        Node* current = tail;

        while (current != nullptr)
        {
            cout << current->data;

            if (current->prev != nullptr)
                cout << " <-> ";

            current = current->prev;
        }

        cout << endl;
    }

    void insertAtStart(int val)
    {
        Node* newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtPosition(int pos, int val)
    {
        if (pos < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }

        Node* current = head;
        int index = 0;

        while (current != nullptr && index < pos)
        {
            current = current->next;
            index++;
        }

        if (current == nullptr)
        {
            if (index == pos)
                insertAtEnd(val);
            else
                cout << "Invalid position" << endl;

            return;
        }

        Node* newNode = new Node(val);

        newNode->prev = current->prev;
        newNode->next = current;

        current->prev->next = newNode;
        current->prev = newNode;
    }

    void deleteFromStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    void deleteFromEnd()
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = tail;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    void deleteValue(int val)
    {
        Node* current = head;

        while (current != nullptr && current->data != val)
            current = current->next;

        if (current == nullptr)
        {
            cout << "Value not found" << endl;
            return;
        }

        if (current == head)
        {
            deleteFromStart();
            return;
        }

        if (current == tail)
        {
            deleteFromEnd();
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
    }

    void reverse()
    {
        Node* current = head;

        while (current != nullptr)
        {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }

        Node* temp = head;
        head = tail;
        tail = temp;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtPosition(1, 20);

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    list.insertAtStart(5);
    list.insertAtEnd(40);

    cout << "After insertions: ";
    list.displayForward();

    list.deleteFromStart();

    cout << "After deleting from start: ";
    list.displayForward();

    list.deleteFromEnd();

    cout << "After deleting from end: ";
    list.displayForward();

    list.deleteValue(20);

    cout << "After deleting 20: ";
    list.displayForward();

    list.reverse();

    cout << "After reverse: ";
    list.displayForward();

    cout << "Backward after reverse: ";
    list.displayBackward();

    return 0;
}
