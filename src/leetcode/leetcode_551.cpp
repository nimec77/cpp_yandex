#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool checkRecord(string& s) {
    int absent = 0;
    int late = 0;
    for (char i : s) {
        if (i == 'A') {
            absent++;
            if (absent > 1) {
                return false;
            }
        }
        if (i == 'L') {
            late++;
            if (late > 2) {
                return false;
            }
        } else {
            late = 0;
        }
    }
    return true;
}
int main() {
    return 0;
}