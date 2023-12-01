#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

map<char, char> lowerToUpperMap{
        {'a', 'A'},
        {'b', 'B'},
        {'c', 'C'},
        {'d', 'D'},
        {'e', 'E'},
        {'f', 'F'},
        {'g', 'G'},
        {'h', 'H'},
        {'i', 'I'},
        {'j', 'J'},
        {'k', 'K'},
        {'l', 'L'},
        {'m', 'M'},
        {'n', 'N'},
        {'o', 'O'},
        {'p', 'P'},
        {'q', 'Q'},
        {'r', 'R'},
        {'s', 'S'},
        {'t', 'T'},
        {'u', 'U'},
        {'v', 'V'},
        {'w', 'W'},
        {'x', 'X'},
        {'y', 'Y'},
        {'z', 'Z'}
};

map<char, char> upperToLowerMap{
        {'A', 'a'},
        {'B', 'b'},
        {'C', 'c'},
        {'D', 'd'},
        {'E', 'e'},
        {'F', 'f'},
        {'G', 'g'},
        {'H', 'h'},
        {'I', 'i'},
        {'J', 'j'},
        {'K', 'k'},
        {'L', 'l'},
        {'M', 'm'},
        {'N', 'n'},
        {'O', 'o'},
        {'P', 'p'},
        {'Q', 'q'},
        {'R', 'r'},
        {'S', 's'},
        {'T', 't'},
        {'U', 'u'},
        {'V', 'v'},
        {'W', 'w'},
        {'X', 'x'},
        {'Y', 'y'},
        {'Z', 'z'}
};


string convertToGoodString(const string &probablyBadString) {
    if (probablyBadString.length() <= 1) {
        return probablyBadString;
    }

    vector<int> stack;

    int l = 0, r = 1;
    auto wasAdded = false;
    while (r < probablyBadString.length()) {
        auto left = probablyBadString[l];
        auto right = probablyBadString[r];
        char compareWith;
        if (lowerToUpperMap.count(left)) {
            compareWith = lowerToUpperMap[left];
        } else {
            compareWith = upperToLowerMap[left];
        }
        if (compareWith == right) {
            wasAdded = false;
            r++;
            if (!stack.empty()) {
                if (r == probablyBadString.length()) {
                    break;
                }
                l = stack.back();
                stack.pop_back();
            } else {
                if (r == probablyBadString.length() - 1) {
                    stack.push_back(r);
                    break;
                }
                l = r;
                r++;
            }
        } else {
            wasAdded = true;
            stack.push_back(l);
            l = r;
            r++;
        }
    }
    stringstream result;
    for (int i: stack) {
        result << probablyBadString[i];
    }
    if (wasAdded) {
        result << probablyBadString[r - 1];
    }
    return result.str();
}

int main() {
    string probablyBadString;
    cin >> probablyBadString;
    cout << convertToGoodString(probablyBadString);
}
