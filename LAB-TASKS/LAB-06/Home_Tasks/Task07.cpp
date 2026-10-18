#include <iostream>

using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
    if (x < n && y < n && arr[x][y] == 1) {
        return true;
    }
    return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solArr) {
    if ((x == (n - 1)) && (y == (n - 1))) {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n)) {
        solArr[x][y] = 1;

        if (ratinMaze(arr, x + 1, y, n, solArr)) {
            return true;
        }

        if (ratinMaze(arr, x, y + 1, n, solArr)) {
            return true;
        }

        cout << "Backtrack from (" << x << ", " << y << ")" << endl;
        solArr[x][y] = 0;
        return false;
    }

    return false;
}



int main() {
    int n4 = 4;
    int m4[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int** arr4 = new int*[n4];
    int** sol4 = new int*[n4];
    for (int i = 0; i < n4; i++) {
        arr4[i] = new int[n4];
        sol4[i] = new int[n4];
        for (int j = 0; j < n4; j++) {
            arr4[i][j] = m4[i][j];
            sol4[i][j] = 0;
        }
    }

    cout << "4x4 Maze Execution:" << endl;
    if (ratinMaze(arr4, 0, 0, n4, sol4)) {
        cout << "Solution 4x4:" << endl;
        for (int i = 0; i < n4; i++) {
            for (int j = 0; j < n4; j++) {
                cout << sol4[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found for 4x4 maze." << endl;
    }

    int n3 = 3;
    int m3[3][3] = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };

    int** arr3 = new int*[n3];
    int** sol3 = new int*[n3];
    for (int i = 0; i < n3; i++) {
        arr3[i] = new int[n3];
        sol3[i] = new int[n3];
        for (int j = 0; j < n3; j++) {
            arr3[i][j] = m3[i][j];
            sol3[i][j] = 0;
        }
    }

    cout << "\n3x3 Maze Execution:" << endl;
    if (ratinMaze(arr3, 0, 0, n3, sol3)) {
        cout << "Solution 3x3:" << endl;
        for (int i = 0; i < n3; i++) {
            for (int j = 0; j < n3; j++) {
                cout << sol3[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found for 3x3 maze." << endl;
    }

    for (int i = 0; i < n4; i++) {
        delete[] arr4[i];
        delete[] sol4[i];
    }
    delete[] arr4;
    delete[] sol4;

    for (int i = 0; i < n3; i++) {
        delete[] arr3[i];
        delete[] sol3[i];
    }
    delete[] arr3;
    delete[] sol3;

    return 0;
}