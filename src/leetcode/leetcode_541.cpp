#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string reverseString(string &s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k) {
        reverse(s.begin() + i, s.begin() + min(i + k, n));
    }
    return s;
}

int main() {
    return 0;
}