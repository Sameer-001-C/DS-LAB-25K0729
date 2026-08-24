#include <iostream>
using namespace std;




int main()
{
    int rows;
    cout << "Enter number of rows in your 2D array: ";
    cin >> rows;


    int **arr = new int*[rows];

    int *size = new int[rows];

    for(int i = 0; i < rows; i++)
    {
        cout << "Enter number of columns in row " << i+1 << ": ";
        cin >> size[i];

        arr[i] = new int[size[i]];
        
    }

    for(int i = 0; i < rows; i++)
    {
        cout << "Enter " << size[i] << " elements for row " << i+1 << ": ";

        for(int j = 0; j < size[i]; j++)
        {
            cin >> arr[i][j];
        }
    }



    cout << "\n=====2D Array======\n" << endl;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    int *sum = new int[rows]();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < size[i]; j++)
        {
            sum[i] += arr[i][j];
        }
    }

    for(int i = 0; i < rows; i++)
    {
        cout << "Sum of row " << i+1 << ": " << sum[i] << endl;
        cout << "Average of row " << i+1 << ": " << (double)sum[i]/size[i] << endl;
    }

    int max = size[0];
    int min = size[0];

    int idxMax = 0;
    int idxMin = 0;

    for(int i = 0; i < rows; i++)
    {
        if(size[i] > max)
        {
            max = size[i];
            idxMax = i;
        }
        else if(size[i] < min)
        {
            min = size[i];
            idxMin = i;
        }
    }


    cout << "Row with the most elements: " << idxMax + 1 << " (" << max << " elements)" << endl;
    cout << "Row with the least elements: " << idxMin + 1 << " (" << min << " elements)" << endl;

    for(int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] size;
    delete[] sum;

    return 0;
}