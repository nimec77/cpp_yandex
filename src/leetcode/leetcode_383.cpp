#include <iostream>
#include <array>

using namespace std;

bool canConstruct(const string& ransomNote, const string& magazine) {
    array<int, 26> letters = {0};
    for (char c : magazine) {
        letters[c - 'a']++;
    }
    for (char c : ransomNote) {
        if (--letters[c - 'a'] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string ransomNote;
    string magazine;
    getline(cin, ransomNote);
    getline(cin, magazine);
    cout << canConstruct(ransomNote, magazine) << endl;
    return 0;
}
