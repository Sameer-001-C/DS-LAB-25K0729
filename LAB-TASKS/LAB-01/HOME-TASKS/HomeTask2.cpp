#include <iostream>
using namespace std;



class Matrix
{

private:
    int rows;
    int cols;
    int **data;

public:

    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        data = new int* [rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }

        cout << "Matrix constructor called for: " << rows << "x" << cols << " matrix." << endl;
    }

    Matrix(const Matrix &other)
    {
        rows = other.rows;
        cols = other.cols;

        data = new int* [rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }

        cout << "Matrix copy constructor called for: " << rows << "x" << cols << " matrix." << endl;
    }


    Matrix & operator = (const Matrix &other)
    {
        if (this != &other)
        {
            cout << "Matrix assignment operator called for: " << rows << "x" << cols << " matrix." << endl;

            for(int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }

            delete[] data;

            rows = other.rows;
            cols = other.cols;

            data = new int* [rows];

            for (int i = 0; i < rows; i++)
            {
                data[i] = new int[cols];

                for (int j = 0; j < cols; j++)
                {
                    data[i][j] = other.data[i][j];
                }
            }

            
        }

        return *this;
    }

    void set(int r, int c, int value)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = value;
        }
    }

    int get(int r, int c) const
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            return data[r][c];
        }
        
        cout << "Invalid matrix indices." << endl;
        return -1;
    }


    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }

    Matrix operator + (const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrix dimensions do not match for addition." << endl;
            return *this;
        }

        Matrix sum(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sum.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return sum;
    }



    ~Matrix()
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }

        delete[] data;

        cout << "Matrix destructor called for: " << rows << "x" << cols << " matrix." << endl;
    }




};



int main()
{
    Matrix mat1(2, 3);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(0, 2, 3);
    mat1.set(1, 0, 4);
    mat1.set(1, 1, 5);
    mat1.set(1, 2, 6);

    cout << "Matrix 1:" << endl;
    mat1.display();

    Matrix mat2(2, 3);
    mat2.set(0, 0, 7);
    mat2.set(0, 1, 8);
    mat2.set(0, 2, 9);
    mat2.set(1, 0, 10);
    mat2.set(1, 1, 11);
    mat2.set(1, 2, 12);

    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix mat3 = mat1 + mat2;

    cout << "Matrix 3 (Sum):" << endl;
    mat3.display();

    cout << "======= Creating matrix 4 as a copy of matrix 1 =========\n" << endl;
    Matrix mat4 = mat1;

    mat1.set(0, 0, 100);

    cout << "======= Matrix 1 and 4 after modifying matrix 1 =========\n" << endl;

    cout << "Matrix 1:" << endl;
    mat1.display();

    cout << "Matrix 4 (Copy of the initial Matrix 1):" << endl;
    mat4.display();

    return 0;
}