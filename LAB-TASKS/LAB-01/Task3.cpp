#include <iostream>
using namespace std;

class Rectangle
{

private:

    int* width;
    int* height;

public:


    Rectangle(int w, int h)
    {
        width = new int;
        height = new int;

        *width = w;
        *height = h;
    }

    int area() const
    {
        return (*width) * (*height);
    }


    void display() const
    {
        cout << "Width: " << *width << endl;
        cout << "Height: " << *height << endl;
        cout << "Area: " << area() << endl;
    }

    int* GetWidth() const
    {
        return width;
    }

    int* GetHeight() const
    {
        return height;
    }


    ~Rectangle()
    {
        delete width;
        delete height;

        cout << "Rectangle destroyed." << endl;
    }


};



int main()
{

    Rectangle r1(4, 5);

    Rectangle r2 = r1;

    cout << "Address stored in r1's width: " << r1.GetWidth() << endl;
    cout << "Address stored in r2's width: " << r2.GetWidth() << endl;

    cout << "\n========== r1 before modifying r2's width ==============\n";
    r1.display();

    *(r2.GetWidth()) = 10;

    cout << "\n========== r1 after modifying r2's width ==============\n";
    r1.display();


    return 0;
}


/*
Since there was no implementation of a copy constructor, the program used a default copy constructor which created a shallow copy.

This means that now, both the pointers point to the same memory address. So modifying one will affect the other.

Because of this, when r1 and r2 go out of scope, their destructors will trigger, which will both delete the same memory address, width and height, twice.

This will cause a double delete operation, which crashes the program.
*/
