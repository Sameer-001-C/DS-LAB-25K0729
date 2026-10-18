#include <iostream>
using namespace std;




bool isSafe(int** arr, int x, int y, int n, bool** visited) {
    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && !visited[x][y]) {
        return true;
    }
    return false;
}



bool ratinMaze(int** arr, int x, int y, int n, int** solArr, bool** visited) {
    if (x == (n - 1) && y == (n - 1)) {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, visited)) {
        solArr[x][y] = 1;
        visited[x][y] = true;

        if (ratinMaze(arr, x + 1, y, n, solArr, visited)) return true;
        if (ratinMaze(arr, x, y + 1, n, solArr, visited)) return true;
        if (ratinMaze(arr, x - 1, y, n, solArr, visited)) return true;
        if (ratinMaze(arr, x, y - 1, n, solArr, visited)) return true;

        solArr[x][y] = 0;
        visited[x][y] = false;
        return false;
    }

    return false;
}




int main() {
    int n = 4;
    int m[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1}
    };

    int** arr = new int*[n];
    int** solArr = new int*[n];
    bool** visited = new bool*[n];

    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        solArr[i] = new int[n];
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = m[i][j];
            solArr[i][j] = 0;
            visited[i][j] = false;
        }
    }

    if (ratinMaze(arr, 0, 0, n, solArr, visited)) {
        cout << "Solution 4-Directional Maze:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] solArr[i];
        delete[] visited[i];
    }
    delete[] arr;
    delete[] solArr;
    delete[] visited;

    return 0;
}