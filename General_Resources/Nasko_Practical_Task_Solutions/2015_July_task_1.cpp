#include <iostream>

using namespace std;

const int MAX_M = 10;
const int MAX_N = 10;

void subsample(float matrix[][MAX_N], int rows, int cols) {
    bool end = false;
    for (int i = 0; i < rows; ++i) {
        if (end) {
            break;
        }

        for (int j = 0; j < cols; ++j) {

            float result = 0;
            int count = 0;
            for (int k = i * 2; k <= i * 2 + 1 ; ++k) {
                for (int l = j * 2; l <= j * 2 + 1; ++l) {
                    if (k < rows && l < cols) {
                        result += matrix[k][l];
                        count++;
                    }
                }
            }

            if (count == 0) {
                end = true;
                break;
            }
            cout << (result / count) << " ";
        }

        cout << endl;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    float matrix[MAX_M][MAX_N];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    subsample(matrix, rows, cols);
}


