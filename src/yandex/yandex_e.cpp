#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> romToArabic{
        {"M", 1000},
        {"D", 500},
        {"C", 100},
        {"L", 50},
        {"X", 10},
        {"V", 5},
        {"I", 1},
};

string threeSymbol;
int threeCount = 0;
map<string, int> globalCount;


bool checkSymbol(const string &symbol) {
    if (symbol == "V" || symbol == "L" || symbol == "D") {
        if (globalCount[symbol] > 0) {
            return false;
        }
        globalCount[symbol]++;
    } else {
        if (threeSymbol == symbol) {
            threeCount++;
            if (threeCount > 3) {
                return false;
            }
        } else {
            threeSymbol = symbol;
            threeCount = 1;
        }
    }

    return true;
}

int convertToArabic(const string &romanNumber) {
    int result = 0;

    int prev = INT_MAX;
    for (auto i = 0; i < romanNumber.size(); i++) {
        string currentSymbol = romanNumber.substr(i, 1);
        string nextSymbol = i + 1 < romanNumber.size() ? romanNumber.substr(i + 1, 1) : "";
        if (!checkSymbol(currentSymbol)) {
            return -1;
        }
        auto current = romToArabic[currentSymbol];
        auto next = romToArabic.try_emplace(nextSymbol, 0).first->second;
        if (current < next) {
            result -= current;
        } else {
            if (prev < current) {
                return -1;
            }
            prev = current;
            result += current;
        }
    }

    return result;
}

int main() {
    string romanNumber;
    cin >> romanNumber;
    cout << convertToArabic(romanNumber);
}