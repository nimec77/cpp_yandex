#include <iostream>
#include <cmath>

using namespace std;

void reverseString(vector<char>& s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
        swap(s[l], s[r]);
    }
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (char c : s) {
        cout << c;
    }
    return 0;
}
