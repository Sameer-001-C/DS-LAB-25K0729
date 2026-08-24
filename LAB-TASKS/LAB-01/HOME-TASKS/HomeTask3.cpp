#include <iostream>

using namespace std;

class DynamicArray
{

private:

    int *arr;
    int size;
    int capacity;

public:

    DynamicArray()
    {
        capacity = 1;
        arr = new int[capacity];
        size = 0;
        cout << "Default constructor" << endl;
    }

    DynamicArray(const DynamicArray &other)
    {

        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }

        cout << "Copy Constructor" << endl;
    }

    DynamicArray &operator=(const DynamicArray &other)
    {
        if (this != &other)
        {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        
        cout << "Copy assignment operator" << endl;
        return *this;
        
    }

    int &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            cout << "Invalid index." << endl;
            exit(1);    // had to do some research to implement this line.
        }
    }

    void pushBack(int value)
    {
        if (size == capacity)
        {
            int *temp = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;

            arr = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                arr[i] = temp[i];
            }

            delete[] temp;
        }
        
        arr[size++] = value;
        
    }


    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }

    
    ~DynamicArray()
    {
        cout << "Destructor called" << endl;
        delete[] arr;
    }
};


int main()
{
    DynamicArray ar1;
    ar1.pushBack(100);
    ar1.pushBack(211);
    ar1.pushBack(300);
    ar1.pushBack(420);
    ar1.pushBack(96);
    ar1.pushBack(690);
    ar1.print();
    cout << ar1[1] << endl;
    
    DynamicArray ar2 = ar1;
    
    cout << "Array 2:\n" << endl;
    ar2.print();
    
    DynamicArray ar3;
    
    ar3 = ar1;
    
    cout << "Array 3: \n" << endl;
    
    ar3.print();

    ar3[1] = 999;
    ar3[2] = 888;
    ar3[3] = 777;

    cout << "\n============After modification of array 3 =======\n" << endl;

    cout << "Array 1:\n" << endl;
    ar1.print();

    cout << "Array 2:\n" << endl;
    ar2.print();

    cout << "Array 3:\n" << endl;
    ar3.print();


    return 0;
}
