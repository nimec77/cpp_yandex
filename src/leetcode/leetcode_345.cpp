#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

string reverseVowels(string s) {
    int r = s.size() - 1;
    for (int l = 0; l < r; l++) {
        if (!vowels.count(s[l])) {
            continue;
        }
        while (!vowels.count(s[r]) && l < r) {
            r--;
        }
        if (l < r) {
            swap(s[l], s[r]);
            r--;
        }
    }

    return s;
}

int main() {
    string s;
    cin >> s;
    auto result = reverseVowels(s);
    cout << result << endl;
    return 0;
}
