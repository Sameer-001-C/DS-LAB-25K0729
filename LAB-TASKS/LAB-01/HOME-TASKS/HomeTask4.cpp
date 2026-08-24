#include <iostream>

using namespace std;


/*
Since the program uses pointers, and, there was no copy constructor and copy assignment operator's implementation,
the program, by default, used the default compiler generated copy constructor and performed a shallow copy.

This means that with this shallow copy, two objects would contain a pointer that would point to the same memory location. 

This is problematic because when the destructor is called for one of the objects, it will free the memory for it's pointer,
then, when the destructor is called for the other object, it will try to free the same memory location again.

This double deletion is not allowed and will cause an error.
*/



/*
The corruption is visible, even before the double deletion takes place, and, can be seen through the display function.

After b2 is equated to b1, b2's data is changed, however, this change is also reflected in b1's data, which is not what 
we expected from the program, and, we can already tell that there is a problem with the program, even before the double deletion takes place.

*/




class Buffer
{

private:
    int *data;
    int length;

public:
    Buffer(int len)
    {
        length = len;
        data = new int[length];
        for (int i = 0; i < length; i++)
        {
            data[i] = 0;
        }

        cout << "Buffer constructor called" << endl;
    }


    Buffer(const Buffer &other)
    {
        length = other.length;
        data = new int[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
        cout << "Buffer copy constructor called" << endl;
    }


    Buffer &operator=(const Buffer &other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < length)
        {

            data[index] = value;
        }
    }

    void display() const
    {
        for (int i = 0; i < length; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    ~Buffer()
    {
        cout << "Buffer destructor called" << endl;
        delete[] data;
    }
};



int main()
{
    Buffer b1(5);
    b1.setValue(0, 5);
    Buffer b2 = b1; // uses the compiler-generated copy constructor
    b2.setValue(1, 20);
    b1.display();
    b2.display();
    return 0; // both b1 and b2 are destroyed here
}


