#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>


using namespace std;

string convertFromUnicode(const string &s) {
    stringstream ss;
    int i = 0;
    if (s.length() < 6) {
        return s;
    }
    for (; i < s.length() - 4; i++) {
        if (s[i] == '\\' && tolower(s[i + 1]) == 'u') {
            auto unicode = s.substr(i + 2, 4);
            auto code = stoi(unicode);
            ss << char(code);
            i += 5;
        } else {
            ss << s[i];
        }
    }
    ss << s.substr(i);
    return ss.str();
}

bool isIsomorphic(string &s, string &t) {
    unordered_map<char, char> sTotMap;
    set<char> addedChars;

    auto sDecode = convertFromUnicode(s);
    auto tDecode = convertFromUnicode(t);
    if (sDecode.size() != tDecode.size()) {
        return false;
    }

    for (int i = 0; i < sDecode.length(); i++) {
        auto sTot = sTotMap.find(sDecode[i]);
        if (sTot == sTotMap.end()) {
            if (addedChars.count(tDecode[i]) != 0) {
                return false;
            }
            sTotMap[sDecode[i]] = tDecode[i];
            addedChars.insert(tDecode[i]);
        } else if (sTot->second != tDecode[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    string t;
    cin >> s >> t;
    auto res = isIsomorphic(s, t);
    cout << res << endl;
    return 0;
}
