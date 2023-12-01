#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string &s, string &t) {
    unordered_map<char, int> sMap;
    if (s.size() != t.size()) {
        return false;
    }
    for (int i = 0; i < s.size(); i++) {
        sMap[s[i]]++;
        sMap[t[i]]--;
    }

    for (auto & it : sMap) {
        if (it.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << isAnagram(s, t) << endl;
    return 0;
}
