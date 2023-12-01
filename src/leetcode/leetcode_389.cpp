#include <iostream>
#include <array>

using namespace std;

char findTheDifference(const string &s, const string &t) {
    array<int, 26> arr = {0};
    for (char c: s) {
        arr[c - 'a']++;
    }
    for (char c: t) {
        arr[c - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] == -1) {
            return 'a' + i;
        }
    }
    return 'a';
}

char findTheDifference2(const string &s, const string &t) {
    auto sum = 0;
    for (auto &c: s) {
        sum += c;
    }
    for (auto &c: t) {
        sum -= c;
    }
    return sum;
}

int main() {
    string s, t;
    cin >> s >> t;
    return 0;
}
//
// Created by Dmitry Seloustev on 24.11.2023.
//
