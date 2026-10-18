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


void solveNQueensCount(int board[], int n, int row, int& count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueensCount(board, n, row + 1, count);
            board[row] = -1;
        }
    }
    
}



int main() {
    int n = 8;
    int* board = new int[n];
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }

    int totalCount = 0;
    solveNQueensCount(board, n, 0, totalCount);

    cout << "Total solutions for N = " << n << ": " << totalCount << endl;

    delete[] board;
    return 0;
}