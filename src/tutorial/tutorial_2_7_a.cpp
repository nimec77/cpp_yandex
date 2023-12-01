#include <vector>


std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    int max = matrix[0][0];
    size_t max_i = 0;
    size_t max_j = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    return {max_i, max_j};
}

int main() {
    return 0;
}
