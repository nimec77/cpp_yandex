#include <iostream>

using namespace std;

bool isPalindrome(string &s) {
    size_t n = s.size();
    if (n < 2) {
        return true;
    }
    size_t r = n - 1;
    for (size_t l = 0; l < r; l++) {
        if (s[l] == ' ') {
            continue;
        }
        while (s[r] == ' ') {
            r--;
        }
        if (s[l] != s[r]) {
            return false;
        }
        r--;
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);
    auto res = isPalindrome(s);
    cout << (res ? "YES" : "NO") << endl;
    return 0;
}
