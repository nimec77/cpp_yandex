#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    if (s.length() == 1) {
        return true;
    }

    int r = s.length() - 1;
    for (int l = 0; l < s.length() && l < r; l++) {
        if (!isalnum(s[l])) {
            continue;
        }
        while (!isalnum(s[r]) && l < r) {
            r--;
        }
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        r--;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    auto result = isPalindrome(s);
    cout << result << endl;
    return 0;
}
