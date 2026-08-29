#include <iostream>
using namespace std;


int** createMatrix(int row, int col)
{
    int** matrix = new int* [row];

    for(int i = 0; i < row; i++)
    {
        matrix[i] = new int [col];
    }

    return matrix;
}

void destroyMatrix(int** matrix, int row)
{
    for(int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void displayMatrix(int** matrix, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << "\t";
        }

        cout << endl;
    }
}


int** addMatrix(int** matrixA, int** matrixB, int row, int col)
{
    int** temp = new int* [row];

    for(int i = 0; i < row; i++)
    {
        temp[i] = new int [col];

        for(int j = 0; j < col; j++)
        {
            temp[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return temp;
}


int** multiplyMatrix(int** matrixA, int** matrixB, int rowA, int colA, int rowB, int colB)
{
    int** temp = new int* [rowA];

    for(int i = 0; i < rowA; i++)
    {
        temp[i] = new int [colB];

        for(int j = 0; j < colB; j++)
        {
            temp[i][j] = 0;

            for(int k = 0; k < colA; k++)
            {
                temp[i][j] += matrixA[i][k] * matrixB[k][j];
            }  
        }
    }

    return temp;
}


void takeInput(int** matrix, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter element for row " << i+1 << " col " << j+1 << " :";
            cin >> matrix[i][j];
        }
    }
}


void displayMenu()
{
    cout << "\n====== MENU ========\n" << endl;

    cout << "1. Add Matrices." << endl;
    cout << "2. Multiply Matrices." << endl;
    cout << "3. Display Matrices." << endl;
    cout << "4. Exit Program." << endl;

    cout << "\nEnter your choice: ";

}






int main()
{
    int rowA, colA, rowB, colB;

    cout << "Enter the row and column for matrix A: ";
    cin >> rowA >> colA;

    cout << "Enter the row and column for matrix B: ";
    cin >> rowB >> colB;

    int** matrixA = createMatrix(rowA, colA);
    int** matrixB = createMatrix(rowB, colB);

    cout << "\n======= Matrix A =======\n" << endl;

    takeInput(matrixA, rowA, colA);

    cout << "\n======= Matrix B =======\n" << endl;
    
    takeInput(matrixB, rowB, colB);

    int** result;


    int choice = -1;

    while(choice != 4)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1: // add

            if(rowA != rowB || colA != colB)
            {
                cout << "\nERROR ======= Cannot add the two matrices. Matrix dimensions donot match. ======= ERROR" << endl;
                break;
            }

            result = addMatrix(matrixA, matrixB, rowA, colA);

            cout << "Addition Successful!\n" << endl;

            cout << "======= Resultant Matrix =======\n" << endl;

            displayMatrix(result, rowA, colA);
            destroyMatrix(result, rowA);

            break;

        case 2: // multiply

            if(colA != rowB)
            {
                cout << "\nERROR ======= Cannot multiply the two matrices. Matrix dimensions donot match. ======= ERROR" << endl;
                break;
            }

            result = multiplyMatrix(matrixA, matrixB, rowA, colA, rowB, colB);

            cout << "\nMultiplication Successful!\n" << endl;

            cout << "======= Resultant Matrix =======\n" << endl;

            displayMatrix(result, rowA, colB);
            destroyMatrix(result, rowA);

            break;

        case 3: // display

            cout << "\n======= Display =======\n" << endl;

            cout << "======= Matrix A =======\n" << endl;

            displayMatrix(matrixA, rowA, colA);

            cout << "======= Matrix B =======\n" << endl;

            displayMatrix(matrixB, rowB, colB);

            break;

        case 4: // exit program
            cout << "\nExiting..." << endl;
            break;
        
        default:    // invalid choice. please enter again.

            cout << "\nERROR ======= Invalid Choice! Please try again. ======= ERROR" << endl;
            break;

        }
    }

    destroyMatrix(matrixA, rowA);
    destroyMatrix(matrixB, rowB);


    return 0;
}