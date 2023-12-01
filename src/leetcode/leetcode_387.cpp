#include <iostream>
#include <array>

using namespace std;

int firstUniqChar(string s) {
    array<int, 26> count = {0};
    for (char i : s) {
        count[i - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;
    return 0;
}
