#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Cell struct to store a cell's row, col and cost
struct Cell {
    int row, col, cost;
    Cell(int x, int y, int z) : row(x), col(y), cost(z) {}
};

// Utility function to check whether a given cell (row, col) is a valid
// cell or not.
bool isValid(int row, int col, int ROW, int COL) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Utility function to calculate the 'h' heuristic.
int calculateHValue(int row, int col, int destRow, int destCol) {
    // Manhattan distance on a square grid
    return abs(row - destRow) + abs(col - destCol);
}

    // A* algorithm
    vector<pair<int, int>> aStar(int ROW, int COL, pair<int, int> src, pair<int, int> dest) {
    // Create a closed list and initialise it to false which means
    // that no cell has been included yet
    // This closed list is implemented as a boolean 2D array
    vector<vector<bool>> closedList(ROW, vector<bool>(COL, false));

    // Create an open list and initialise it to false which means
    // that no cell has been included yet
    // This open list is implemented as a boolean 2D array
    vector<vector<bool>> openList(ROW, vector<bool>(COL, false));

    // Create a 2D array to store the 'g' and 'h' values
    vector<vector<int>> gH(ROW, vector<int>(COL));

    // Create a 2D array to store the parent of each cell
    vector<vector<pair<int, int>>> parent(ROW, vector<pair<int, int>>(COL));

    // Create a priority queue to store the cells to be evaluated
    // The elements in the priority queue are sorted by their 'f' values
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    // Initialise the source cell
    src.first = src.first;
    src.second = src.second;
    gH[src.first][src.second] = 0;
    parent[src.first][src.second] = make_pair(-1, -1);

    // Push the source cell to the priority queue
    pq.push(Cell(src.first, src.second, 0));
    openList[src.first][src.second] = true;

    // A* algorithm
    while (!pq.empty()) {
        // Get the cell with the minimum 'f' value from the priority queue
        Cell p = pq.top();
        pq.pop();

        // Get the row and column of the current cell
        int row = p.row;
        int col = p.col;

        // If the current cell is the destination cell, then we are done
        if (row == dest.first && col == dest.second) {
            vector<pair<int, int>> path;
            pair<int, int> curr = dest;

            while (parent[curr.first][curr.second] != make_pair(-1, -1)) {
                path.push_back(curr);
                curr = parent[curr.first][curr.second];
            }

            path.push_back(src);
            reverse(path.begin(), path.end());
            return path;
        }

    // If the current cell is not the destination cell
    // then mark it as visited and push it to the closed list
    closedList[row][col] = true;

    // Check all the neighbours of the current cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) == abs(j)) {
                continue;
            }

            // Get the row and column of the neighbour cell
            int r = row + i;
            int c = col + j;

            // If the neighbour cell is not a valid cell or it is
            // already in the closed list, then continue
            if (!isValid(r, c, ROW, COL) || closedList[r][c]) {
                continue;
            }

            // If the neighbour cell is not in the open list, then
            // add it to the open list and calculate its 'g' and 'h' values
            if (!openList[r][c]) {
                gH[r][c] = gH[row][col] + 1;
                h = calculateHValue(r, c, dest.first, dest.second);
                parent[r][c] = make_pair(row, col);
                pq.push(Cell(r, c, gH[r][c] + h));
                openList[r][c] = true;
            }
        }
    }
}

// If the destination is not reached or found
return vector<pair<int, int>>();
}

int main() 
{
    // Set the number of rows and columns of the grid
    int ROW = 10;
    int COL = 10;

    // Set the source and destination cells
    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(9, 9);

    // Get the path
    vector<pair<int, int>> path = aStar(ROW, COL, src, dest);

    // If the path is not empty, then it means a path exists
    if (!path.empty()) {
        cout << "Path exists:" << endl;
        for (auto i : path) {
            cout << "(" << i.first << ", " << i.second << ") ";
        }
    } else {
        cout << "No path exists" << endl;
    }

    return 0;
}



