#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getRow(int rowIndex) {
    auto numRows = rowIndex + 1;
    if (numRows == 1) {
        return {1};
    }
    vector<int> result = {1};
    for (int i = 1; i < numRows; i++) {
        vector<int> row(i + 1);
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                row[j] = 1;
                continue;
            }
            row[j] = result[j - 1] + result[j];
        }
        result = row;
    }
    return result;
}

int main() {
    int numRows;
    cin >> numRows;
    return 0;
}
