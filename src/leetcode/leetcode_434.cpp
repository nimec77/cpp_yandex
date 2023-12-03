#include <vector>
#include <iostream>
#include <array>

using namespace std;

int countSegments(const string& s) {
    int count = 0;
    bool inWord = false;
    for (char i : s) {
        if (i != ' ' && !inWord) {
            inWord = true;
            count++;
        } else if (i == ' ' && inWord) {
            inWord = false;
        }
    }
    return count;
}

int main() {
}
