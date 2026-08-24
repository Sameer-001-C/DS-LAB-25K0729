#include <iostream>
using namespace std;


class SafeArray
{

private:

    int *arr;
    int size;

public:

    SafeArray(int size)
    {
        this->size = size;
        arr = new int[size];

        cout << "Constructor called" << endl;
    }


    void set(int pos, int val)
    {
        if(pos < 0 || pos >= size)
        {
            cout << "Boundary Error" << endl;
            return;
        }

        arr[pos] = val;
    }


    int get(int pos)
    {
        if(pos < 0 || pos >= size)
        {
            cout << "Boundary Error" << endl;
            return -1;
        }

        return arr[pos];
    }


    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }







    ~SafeArray()
    {
        cout << "Destructor called" << endl;
        delete[] arr;
    }


};



int main()
{
    SafeArray arr(5);


    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    arr.set(3, 40);
    arr.set(4, 50);

    arr.display();


    cout << "Element at index 0: " << arr.get(0) << endl;
    cout << "Element at index 1: " << arr.get(1) << endl;
    cout << "Element at index 2: " << arr.get(2) << endl;
    cout << "Element at index 3: " << arr.get(3) << endl;
    cout << "Element at index 4: " << arr.get(4) << endl;



    cout << "Element at index 5: " << arr.get(5) << endl;
    cout << "Element at index -1: " << arr.get(-1) << endl;

    

    cout << "Setting Element at index 5: ";
    arr.set(5, 60);


    cout << "\n======== Displaying array again ========\n" << endl;

    arr.display();

    return 0;

}