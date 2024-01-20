#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string reverseWords(string s) {
    string res;
    int i = 0;
    while (i < s.size()) {
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i >= s.size()) break;
        int j = i + 1;
        while (j < s.size() && s[j] != ' ') {
            j++;
        }
        auto tmp = s.substr(i, j - i);
        reverse(tmp.begin(), tmp.end());
        if (res.size() == 0) {
            res = tmp;
        }
        else {
            res += " " + tmp;
        }
        i = j + 1;
    }
    return res;
}


int main() {
    return 0;
}
