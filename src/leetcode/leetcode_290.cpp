#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool wordPattern(string pattern, const string &s) {
    stringstream ss(s);
    string word;
    unordered_map<char, string> map;
    unordered_set<string> set;
    int i = 0;
    while (getline(ss, word, ' ')) {
        auto it = map.find(pattern[i]);
        if (it == map.end()) {
            if (set.find(word) != set.end()) {
                return false;
            }
            map[pattern[i]] = word;
            set.insert(word);
        } else if (it->second != word) {
            return false;
        }
        i++;
    }
    if (i != pattern.size()) {
        return false;
    }

    return true;
}

int main() {
    string pattern;
    string s;
    getline(cin, pattern);
    getline(cin, s);
    cout << wordPattern(pattern, s) << endl;
    return 0;
}
