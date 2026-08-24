#include <iostream>
using namespace std;


int* resizeArray(int *arr, int oldSize, int newSize)
{
	if(oldSize == newSize)
	{
		return arr;
	}
	
	int *newArray = new int[newSize];
	
	int min = (oldSize < newSize) ? oldSize : newSize;
	
	for(int i = 0; i < min; i++)
	{
		newArray[i] = arr[i];
	}
	
	delete []arr;
	
	return newArray;
}


int main()
{
	int size;
	cout << "Enter size of your array: ";
	cin >> size;
	
	int *arr = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		cout << "Enter element " << i+1 << ": ";
		cin >> arr[i];
	}
	
	int choice = -1;
	
	//cout << "Menu\n1. Grow Array\n2. Shrink Array\n3. Display Array\n4. Exit\n" << endl;
	//cout << "\nEnter choice: ";
	//cin >> choice;
	
	int newSize = 0;
	
	while(choice != 4)
	{
		cout << "\nMenu\n1. Grow Array\n2. Shrink Array\n3. Display Array\n4. Exit\n" << endl;
		cout << "\nEnter choice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				cout << "Enter a new larger size: ";
				cin >> newSize;
				
				if(newSize < size)
				{
					cout << "New size entered is smaller than previous size!" << endl;
					cout << "Previous size: " << size << endl;
					break;
				}
				
				arr = resizeArray(arr, size, newSize);
				
				for(int i = size; i < newSize; i++)
				{
					cout << "Enter element " << i+1 << ": ";
					cin >> arr[i];
				}
				
				size = newSize;
			
				break;
			case 2:
				cout << "Enter a new smaller size: ";
				cin >> newSize;
				
				if(newSize > size)
				{
					cout << "New size entered is larger than previous size!" << endl;
					cout << "Previous size: " << size << endl;
					break;
				}
				
				
				arr = resizeArray(arr, size, newSize);
				
				size = newSize;
				break;
			case 3:
				cout << "\n=======Display======\n" << endl;
				
				for(int i = 0; i < size; i++)
				{
					cout << "Element " << i+1 << ": " << arr[i] << endl;
				}
				
				break;
			case 4:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid choice. Please enter again." << endl;
				
		}
		
		
	}
	
	
	
	delete []arr;
	
	return 0;
}