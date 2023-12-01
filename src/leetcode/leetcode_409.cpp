#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestPalindrome(string &s) {
    unordered_map<char, int> m;

    for (auto c : s) {
        m[c]++;
    }
    int odd = 0;
    int res = 0;
    for (auto & it : m) {
        if (it.second % 2 == 0) {
            res += it.second;
        } else {
            res += it.second - 1;
            odd = 1;
        }
    }
    if (odd > 0) {
        res++;
    }

    return  res;
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}
