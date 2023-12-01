#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> generate(int numRows) {
    if (numRows == 0) {
        return {};
    }
    vector<vector<int>> result(numRows);
    result[0] = {1};
    for (int i = 1; i < numRows; i++) {
        vector<int> row(i + 1);
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                row[j] = 1;
                continue;
            }
            auto prev = result[i - 1];
            row[j] = prev[j - 1] + prev[j];
        }
        result[i] = row;
    }
    return result;
}

int main() {
    int numRows;
    cin >> numRows;
    auto result = generate(numRows);
    cout << result.size() << endl;
    return 0;
}
