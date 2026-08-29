#include <iostream>
using namespace std;


// 8:42 pm start

class DynamicSafeArray
{

private:

    int* arr;
    int capacity;   // refers to the number of elements that can be stored inside the array.
    int size;       // refers to the number of elements currently stored inside the array.

public:

    DynamicSafeArray(int initialCapacity)
    {
        if(initialCapacity > 0)
        {
            capacity = initialCapacity;
        }
        else
        {
            capacity = 1;
        }
        
        size = 0;
        arr = new int [capacity];


        cout << "Constructor Called." << endl;
    }

    void pushBack(int val)
    {
        if(capacity <= size)
        {
            capacity *= 2;
            int* temp = new int [capacity];

            // copying data into a new array
            for(int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
        }

        arr[size++] = val;
    }

    void set(int pos, int val)
    {
        if(pos < 0 || pos >= size)
        {
            cout << "Out of Bounds." << endl;
            return;
        }

        arr[pos] = val;
    }

    int get(int pos)
    {
        if(pos < 0 || pos >= size)
        {
            cout << "Out of Bounds.";
            return -1;
        }

        return arr[pos];
    }

    bool removeAt(int pos)
    {
        if(pos < 0 || pos >= size)
        {
            cout << "Out of Bounds.";
            return false;
        }

        for(int i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i+1];
        }

        size--;
        return true;
    }

    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }

        cout << endl;
    }

    ~DynamicSafeArray()
    {
        cout << "Destructor called." << endl;
        delete[] arr;
    }

};

int main()
{
    DynamicSafeArray arr(2);
    arr.pushBack(0);
    arr.pushBack(1);

    arr.display();

    arr.pushBack(2);
    arr.pushBack(3);
    arr.pushBack(4);
    arr.pushBack(5);
    arr.pushBack(6);

    arr.display();

    arr.removeAt(2);

    arr.display();

    cout << "Element at index 0: " << arr.get(0) << endl;     // will work and return 0
    cout << "Element at index 8: " << arr.get(8) << endl;     // since index 8 is out of bounds, -1 is returned.

    cout << "Setting 100 at index 1." << endl;
    arr.set(1, 100);

    cout << "Setting 700 at index -1." << endl;
    arr.set(-1, 700);

    arr.display();

    return 0;
}