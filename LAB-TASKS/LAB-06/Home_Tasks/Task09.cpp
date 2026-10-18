#include <iostream>
#include <cmath>
using namespace std;



bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}



bool solveNQueens(int board[], int n, int row = 0) {
    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            if (solveNQueens(board, n, row + 1)) {
                return true;
            }

            board[row] = -1;
        }
    }

    return false;
}



void printBoard(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

}




int main() {
    int sizes[] = {4, 5, 6, 8, 2, 3};

    for (int s = 0; s < 6; s++) {
        int n = sizes[s];
        int* board = new int[n];
        for (int i = 0; i < n; i++) {
            board[i] = -1;
        }

        cout << "N = " << n << endl;
        if (solveNQueens(board, n, 0)) {
            printBoard(board, n);
        } else {
            cout << "No solution exists." << endl;
            if (n == 2 || n == 3) {
                cout << "Explanation: On an " << n << "x" << n 
                     << " board, placing " << n 
                     << " queens forces at least two queens to share a row, column, or diagonal due to board dimension constraints." << endl;
            }
        }
        cout << endl;
        delete[] board;
    }

    return 0;
}