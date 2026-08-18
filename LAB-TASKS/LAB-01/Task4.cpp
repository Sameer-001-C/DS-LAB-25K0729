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

    Rectangle(const Rectangle& other) 
    {
        width = new int(*other.width);
        height = new int(*other.height);
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
Since a copy constructor is implemented, the program uses it to create a deep copy.

This means that now, both the pointers point to different memory addresses. So modifying one will not affect the other.

Because of this, when r1 and r2 go out of scope, their destructors will trigger, which will delete their own respective memory addresses for width and height, only once.

This will prevent a double delete operation, which crashed the program in Task 3.
*/
