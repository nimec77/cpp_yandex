#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_set<char> lettersToDelete{'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y'};

unordered_map<char, char> replaceMap{{'b', '1'},
                                     {'f', '1'},
                                     {'p', '1'},
                                     {'v', '1'},
                                     {'c', '2'},
                                     {'g', '2'},
                                     {'j', '2'},
                                     {'k', '2'},
                                     {'q', '2'},
                                     {'s', '2'},
                                     {'x', '2'},
                                     {'z', '2'},
                                     {'d', '3'},
                                     {'t', '3'},
                                     {'l', '4'},
                                     {'m', '5'},
                                     {'n', '5'},
                                     {'r', '6'}};

vector<char> removeDuplicates(vector<char> &arr) {
    vector<char> result;
    for (size_t i = 0; i < arr.size() && result.size() < 3; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

string soundex(string word) {
    auto firstLetter = word[0];
    vector<char> codes;
    for (size_t i = 1; i < word.length(); i++) {
        if (lettersToDelete.find(word[i]) != lettersToDelete.end()) {
            continue;
        }
        auto it = replaceMap.find(word[i]);
        if (it != replaceMap.end()) {
            codes.push_back(it->second);
        }
    }
    codes = removeDuplicates(codes);
    while (codes.size() < 3) {
        codes.push_back('0');
    }
    string res(codes.begin(), codes.end());
    return firstLetter + res;
}

int main() {
    string word;
    cin >> word;
    cout << soundex(word) << endl;
    return 0;
}
