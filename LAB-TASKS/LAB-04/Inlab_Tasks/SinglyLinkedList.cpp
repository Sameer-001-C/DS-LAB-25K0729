#include <iostream>

using namespace std;


template <class T>
class Node
{
	
public:
	
	T data;
	Node<T>* next;
	
	
	Node(T value)
	{
		data = value;
		next = NULL;
	}
	
};



template <class T>
class Singly
{
	
private:
	
	Node<T>* head;
	Node<T>* tail;
	
	
public:
	
	Singly()
	{
		head = NULL;
		tail = NULL;
	}
	
	
	void insertAtTail(T value)
	{
		Node<T>* node = new Node<T>(value);
		
		if(head == NULL)	// if our linked list is entirely empty at first.
		{
			head = node;
			tail = node;
			return;
		}
		
		
		tail->next = node;
		tail = node;
		
	}
	
	
	void insertAtHead(T value)
	{
		Node<T>* node = new Node<T>(value);
		
		node->next = head;
		head = node;
		
		if(tail == NULL)	// this would be true if we were inserting at head while the linked list was empty. That means that our inserted element is the only element in the linked list, and hence, is also the head aswell as the tail.
		{
			tail = node;
		}
	}
	
	
	void insertAfter(int pos, T value)
	{
		if(head == NULL)
		{
		    cout << "Invalid Index." << endl;
		    return;
		}
		
		Node<T>* current = head;
		
		for(int i = 0; i < pos; i++)
		{
			current = current->next;
			
			if(current == NULL)
			{
				cout << "Invalid Index." << endl;
				return;
			}
		}
		
		// now, at this point, current refers to the node at the position we need
		
		Node<T>* insertedNode = new Node<T>(value);
		
		insertedNode->next = current->next;
		
		if(current == tail)
		{
			tail = insertedNode;
		}
		
		current->next = insertedNode;
		
		
	}
	
	
	bool Search(T key)
	{
		if(head == NULL)
		{
			return false;
		}
		
		
		Node<T>* temp = head;
		
		while(temp != NULL)	// meaning that we would traverse until our current element itself is not equal to NULL, meaning, we would never check the data for the last element's next pointer
		{
			if(temp->data == key)
			{
				cout << "\nFound!" << endl;
				return true;
			}
			
			temp = temp->next;
		}
		
		cout << "\nNot Found!" << endl;
		return false;
	}
	
	
	void Display()
	{
		Node<T>* temp = head;
		
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		
		cout << endl;
	}
	
	void DisplayReverse()
	{
		Node<T>* temp = head;
		
		int count = 0;	// refers to the number of elements in our linked list.
		
		while(temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		
		temp = head; // reset
		
		T array[count];	// initializing an array
		
		int i = 0;
		while(temp != NULL)
		{
			array[i] = temp->data;
			temp = temp->next;
			
			i++;
		}
		
		for(int i = count -1; i >= 0; i--)	// displaying in reverse order
		{
			cout << array[i] << " ";
		}
	}
	
	
	~Singly()
	{
		Node<T>* previous = head;
		Node<T>* current = head;
		
		while(current != NULL)
		{
			previous = current;
			current = previous->next;
			delete previous;
			
		}
	}
	
	
};








int main()
{
	Singly<int> list1;
	
	list1.insertAtHead(1);
	list1.insertAtTail(2);
	list1.insertAtTail(3);
	list1.insertAtTail(4);
	list1.insertAtTail(5);
	
	
	list1.Display();
	list1.DisplayReverse();
	
	
	return 0;
}

