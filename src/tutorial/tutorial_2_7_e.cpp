#include <vector>


std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>> &matrix) {
    std::vector<std::vector<int>> result;
    for (size_t i = 0; i < matrix[0].size(); ++i) {
        std::vector<int> row;
        row.reserve(matrix.size());
        for (const auto &j: matrix) {
            row.push_back(j[i]);
        }
        result.push_back(row);
    }
    return result;
}
