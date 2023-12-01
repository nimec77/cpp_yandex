#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    int i = 0;
    int j = 0;
    while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == needle.size()) {
        return i - j;
    }
    return -1;
}

int main() {
    string haystack;
    string needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle) << endl;
    return 0;
}
