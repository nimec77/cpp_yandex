#include <iostream>
#include <list>
#include <string>

using namespace std;

int islandPerimeter(vector<vector<int>> &grid) {
    int perimeter = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                if (i == 0 || grid[i - 1][j] == 0) perimeter++;
                if (i == rows - 1 || grid[i + 1][j] == 0) perimeter++;
                if (j == 0 || grid[i][j - 1] == 0) perimeter++;
                if (j == cols - 1 || grid[i][j + 1] == 0) perimeter++;
            }
        }
    }
    return perimeter;
}


int main() {
    return 0;
}
