#include <iostream>
#include <string>

using namespace std;

vector<string> inputArray() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

string longestCommonPrefix(vector<string> strs) {
    auto str = strs[0];
    int res = str.size();
    for (int i = 1; i < strs.size(); i++) {
        auto cur = 0;
        for (int j = 0; j < strs[i].size(); j++) {
            if (str[j] != strs[i][j]) {
                break;
            }
            cur++;
        }
        res = min(res, cur);
        if (res == 0) {
            return "";
        }
    }
    return str.substr(0, res);
}

int main() {
    vector<string> a = inputArray();
    cout << longestCommonPrefix(a) << endl;
    return 0;
}
