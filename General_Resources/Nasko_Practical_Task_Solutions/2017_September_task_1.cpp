#include <iostream>

using namespace std;

const int MAX_N = 101;
const int MAX_M = 101;

void initializeVisited(bool visited[][MAX_N], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            visited[i][j] = false;
        }
    }
}

void traverse(
        char matrix[][MAX_N],
        bool visited[][MAX_N],
        int rows,
        int cols,
        int row,
        int col,
        char target,
        int &count) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return;
    }
    if (visited[row][col] || matrix[row][col] != target) {
        return;
    }

    visited[row][col] = true;
    count++;

    traverse(matrix, visited, rows, cols, row + 1, col, target, count);
    traverse(matrix, visited, rows, cols, row - 1, col, target, count);
    traverse(matrix, visited, rows, cols, row, col + 1, target, count);
    traverse(matrix, visited, rows, cols, row, col - 1, target, count);
}

void run(char matrix[][MAX_N], bool visited[][MAX_N], int rows, int cols) {
    char target = '4';
    int maxCount = -1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int count = 0;
            if (matrix[i][j] == target && !visited[i][j]) {
                traverse(matrix, visited, rows, cols, i, j, target, count);

                if (maxCount < count) {
                    maxCount = count;
                }
            }
        }
    }

    cout << maxCount;
}

void mutate(char matrix[][MAX_N], int rows, int cols) {
    const int MOVES = 8;
    int xMoves[MOVES] = {0, 0, 1, 1, 1, -1, -1, -1};
    int yMoves[MOVES] = {-1, 1, -1, 0, 1, -1, 0, 1};
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] >= '1' && matrix[i][j] <= '3') {
                matrix[i][j]++;
            } else if (matrix[i][j] == '4') {
                int maxDensityCellsCount = 0;
                for (int k = 0; k < MOVES; ++k) {
                    int newRow = i + xMoves[k];
                    int newCol = j + yMoves[k];

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] == '4') {
                        maxDensityCellsCount++;
                        if (maxDensityCellsCount >= 3) {
                            break;
                        }
                    }
                }

                if (maxDensityCellsCount >= 3) {
                    matrix[i][j] = '3';
                }
            }
        }
    }
}

void task2(char matrix[][MAX_N], int rows, int cols) {
    for (int i = 0; i < 10; ++i) {
        mutate(matrix, rows, cols);
    }
}

void print(char matrix[][MAX_N], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    bool visited[MAX_M][MAX_N];
    int rows, cols;
    cin >> rows >> cols;

    char matrix[MAX_M][MAX_N];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    initializeVisited(visited, rows, cols);
    run(matrix, visited, rows, cols);

    // task2(matrix, rows, cols);
    // print(matrix, rows, cols);
}


