#include <iostream>
using namespace std;


int main()
{
	int **arr;
	
	int rows, cols;
	
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;
	
	arr = new int*[rows];
	
	for(int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << "Enter element for row " << i << " column " << j << ": ";
			cin >> arr[i][j];
		}
	}
	
	//display in proper row/col format
	// computes and display the sum of each row and sum of each column
	// computes and display the transpose of the matrix (also stored in a dynamically allocated 2D array)
	// frees all allocated memory correctly
	
	
// Displaying the matrix:
	cout << "\n=====Matrix======\n" << endl;
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	
	int *sumRow = new int[rows]();
	int *sumCol = new int[cols]();
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			sumRow[i] += arr[i][j];
		}
	}
	
	
	
	for(int j = 0; j < cols; j++)
	{
		for(int i = 0; i < rows; i++)
		{
			sumCol[j] += arr[i][j];
		}
	}
	
	cout << "\n=====Sum of Rows=======\n" << endl;
	for(int i = 0; i < rows; i++)
	{
		cout << "Sum of row " << i << ": " << sumRow[i] << endl;
	}
	
	cout << "\n=====Sum of Cols=========\n" << endl;
	for(int i = 0; i < cols; i++)
	{
		cout << "Sum of col " << i << ": " << sumCol[i] << endl;
	}
	
	/*
		1	2	3
		4	5	6
		7	8	9
		
		1	4	7
		2	5	8
		3	6	9
		
	*/
	
	int **transpose = new int*[cols];
	
	for(int i = 0; i < cols; i++)
	{
		transpose[i] = new int[rows];
	}
	
// copying into the transpose:
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			transpose[j][i] = arr[i][j];
		}
	}


// displaying the transpose:
	cout << "\n=====Transpose of the matrix======\n" << endl;
	for(int i = 0; i < cols; i++)
	{
		for(int j = 0; j < rows; j++)
		{
			cout << transpose[i][j] << "\t";
		}
		cout << endl;
	}


	for(int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}


	for(int i = 0; i < cols; i++)
	{
		delete[] transpose[i];
	}

	delete[] arr;
	delete[] transpose;
	delete[] sumRow;
	delete[] sumCol;
	
}