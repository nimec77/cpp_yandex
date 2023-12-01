#include <iostream>
#include <array>

using namespace std;

bool isSubsequence(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
            if (i == s.size()) {
                return true;
            }
        }
        j++;
    }
    return i == s.size();
}

int main() {
    string s, t;
    cin >> s >> t;
    return 0;
}
