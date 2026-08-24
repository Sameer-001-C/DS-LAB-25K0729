#include <iostream>

using namespace std;

int strlen(const char*str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}



class DynamicString
{
    
private:

    char *data;

public:

    DynamicString(const char *text)
    {
        int size = strlen(text);
        data = new char[size + 1];

        for(int i = 0; i < size; i++)
        {
            data[i] = text[i];
        }

        data[size] = '\0';

        cout << "DynamicString constructor called for: " << data << endl;
    }

    DynamicString(const DynamicString &other)
    {
        int size = strlen(other.data);
        data = new char[size + 1];

        for(int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        data[size] = '\0';

        cout << "DynamicString copy constructor called for: " << data << endl;
    }

    DynamicString & operator = (const DynamicString &other)
    {
        if (this != &other)
        {
            delete []data;

            int size = strlen(other.data);
            data = new char[size + 1];

            for(int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }

            data[size] = '\0';
            cout << "DynamicString assignment operator called for: " << data << endl;
        }

        return *this;
    }

    int length() const
    {
        return strlen(data);
    }

    void print() const
    {
        cout << data << endl;
    }

    void setChar(int index, char c)
    {
        if (index >= 0 && index < length())
        {
            data[index] = c;
        }
    }

    ~DynamicString()
    {
        cout << "DynamicString destructor called for: " << data << endl;
        delete []data;
    }


};



int main()
{
    DynamicString str1("String 1");

    cout << "\n=====String 2 declared as String 1=====" << endl;

    DynamicString str2 = str1;

    DynamicString str3("String 3");


    str3 = str1;

    cout << "\n=====After str3's assignment to str1=====" << endl;

    str1.print();
    str2.print();
    str3.print();

    str1.setChar(7, 'X');

    cout << "\n=====After modifying str1=====" << endl;

    str1.print();
    str2.print();
    str3.print();

    return 0;
}
