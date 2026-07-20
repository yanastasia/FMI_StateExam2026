#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cell {
    int x;
    int y;

    Cell(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }
};

const int PossibleDirections = 8;
const int xDirections[PossibleDirections] = {0, 0, 1, 1, 1, -1, -1, -1};
const int yDirections[PossibleDirections] = {-1, 1, -1, 0, 1, -1, 0, 1};

void
traverseConnectedComponent(vector<vector<int>> &matrix, bool **traversed, int rows, int cols, int row, int col,
                           vector<Cell> &cells) {
    if (row < 0 || col < 0 || row >= rows || col >= cols) {
        return;
    }
    if (matrix[row][col] == 0) {
        return;
    }
    if (traversed[row][col]) {
        return;
    }

    cells.push_back(Cell(row, col));
    traversed[row][col] = true;
    for (int i = 0; i < PossibleDirections; ++i) {
        traverseConnectedComponent(matrix, traversed, rows, cols, row + xDirections[i], col + yDirections[i], cells);
    }
}

vector<vector<Cell>> findConnectedComponents(vector<vector<int>> &matrix, int rows, int cols) {
    bool **traversed = new bool *[rows];
    for (int i = 0; i < rows; ++i) {
        traversed[i] = new bool[cols];
        for (int j = 0; j < cols; ++j) {
            traversed[i][j] = false;
        }
    }

    vector<vector<Cell>> areas;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (traversed[i][j]) {
                continue;
            }

            if (matrix[i][j] != 0) {
                vector<Cell> component;
                traverseConnectedComponent(matrix, traversed, rows, cols, i, j, component);
                areas.push_back(component);
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] traversed[i];
    }

    delete[] traversed;

    return areas;
}

double getAverageContrast(vector<vector<int>> &matrix, vector<Cell> &component) {
    double total = 0;
    for (Cell &cell: component) {
        total += matrix[cell.x][cell.y];
    }

    return total / component.size();
}

struct Component {
    double averageValue;
    Cell startCell;
};

bool componentComparator(Component &first, Component &second) {
    return first.averageValue < second.averageValue;
}

void printComponents(vector<vector<int>> &matrix, int rows, int cols) {
    vector<vector<Cell>> areas = findConnectedComponents(matrix, rows, cols);
    vector<Component> components;
    for (vector<Cell> &cells: areas) {
        components.push_back({getAverageContrast(matrix, cells), cells[0]});
    }

    sort(components.begin(), components.end(),
         [](const Component &first, const Component &second) { return first.averageValue > second.averageValue; });

    for (Component &component: components) {
        cout << component.startCell.x << " " << component.startCell.y << std::endl;
        cout << component.averageValue << endl;
    }
}

int main() {
    const int m = 6;
    const int n = 6;
    vector<vector<int>> matrix = {
            {170, 0,  0,   255, 221, 0},
            {68,  0,  17,  0,   0,   68},
            {221, 0,  238, 136, 0,   255},
            {0,   0,  85,  0,   136, 238},
            {238, 17, 0,   68,  0,   255},
            {85,  170, 0,   221, 17,  0}
    };

    printComponents(matrix, m, n);
}