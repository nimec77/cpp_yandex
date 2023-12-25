#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> findWords(vector<string> &words) {
    unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    vector<unordered_set<char>> rows{row1, row2, row3};
    vector<string> result;
    for (auto &word : words) {
        int i = 0;
        for (; i < rows.size(); ++i) {
            if (rows[i].count(tolower(word[0])) != 0) {
                break;
            }
        }
        bool flag = true;
        for (auto &c : word) {
            if (rows[i].count(tolower(c)) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
}