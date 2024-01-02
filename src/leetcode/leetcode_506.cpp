#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> findRelativeRang(vector<int> &score) {
    vector<string> res(score.size());
    vector<int> index(score.size());
    for (int i = 0; i < score.size(); ++i) {
        index[i] = i;
    }
    sort(index.begin(), index.end(), [&score](int a, int b) { return score[a] > score[b]; });
    for (int i = 0; i < score.size(); ++i) {
        if (i == 0) {
            res[index[i]] = "Gold Medal";
        } else if (i == 1) {
            res[index[i]] = "Silver Medal";
        } else if (i == 2) {
            res[index[i]] = "Bronze Medal";
        } else {
            res[index[i]] = to_string(i + 1);
        }
    }
    return res;
}

int main() {
    return 0;
}