#include <iostream>
using namespace std;


class SafeMatrix
{

private:

    int rows;
    int cols;

    int** arr;

public:

    SafeMatrix(int r, int c)
    {
        rows = r;
        cols = c;

        arr = new int* [rows];
        
        for(int i = 0; i < rows; i++)
        {
            arr[i] = new int [cols];
        }

        cout << "Parametrized constructor called for a " << rows << " by" << cols << " matrix." << endl;

    }

    void set(int r, int c, int val)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Boundary Error." << endl;
            return;
        }

        arr[r][c] = val;
    }


    int get(int r, int c)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Boundary Error." << endl;
            return -1;
        }

        return arr[r][c];
    }

    void display()
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << "\t";
            }

            cout << endl;
        }
    }


    ~SafeMatrix()
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }


};

int main()
{
    SafeMatrix mat1(4,4);

    int count = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            mat1.set(i, j, count++);
        }
    }

    mat1.display();

    cout << "\n======== Setting 0 at mat1[4][3] ==========" << endl;
    mat1.set(4, 3, 0); // this would be invalid since the first parameter, 4, is greater than the max row index access possible.

    cout << "\n======== Setting 1 at mat1[1][5] ==========" << endl;
    mat1.set(1, 5, 1); // this would also be invalid since the second parameter, 5, is greater than the max col index access possible.

    cout << "\n======== Setting 2 at mat1[-1][2] ==========" << endl;
    mat1.set(-1, 2, 2); // also invalid since -1 is less than the min row index access possible

    cout << "Getting element mat1[4][0] : " << mat1.get(4,0) << endl;    // error since 4 is greater than or equal to number of rows
    cout << "Getting element mat1[-1][0] : " << mat1.get(-1,0) << endl;    // error since -1 is less 0, which is the minimum safe index access possible
    cout << "Getting element mat1[0][4] : " << mat1.get(0,4) << endl;    // error since 4 is greater than or equal to number of cols

    cout << "\n===========Matrix after invalid sets/gets=========\n" << endl;

    mat1.display();

    cout << "\n======== Setting 100 at mat1[0][0] ==========" << endl;
    mat1.set(0, 0, 100);

    cout << "\n======== Setting -200 at mat1[3][3] ==========" << endl;
    mat1.set(3, 3, -200);

    cout << "Getting element mat1[0][1] : " << mat1.get(0,1) << endl; 
    cout << "Getting element mat1[2][3] : " << mat1.get(2,3) << endl; 



    cout << "\n===========Matrix after valid sets/gets=========\n" << endl;

    mat1.display();
    


    return 0;
}
