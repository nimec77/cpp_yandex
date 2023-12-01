#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string columnTitle) {
    int result = 0;
    for (auto ch: columnTitle) {
        int digit = ch - 'A' + 1;
        result = result * 26 + digit;
    }

    return result;
}

int main() {
    string columnTitle;
    cin >> columnTitle;
    auto result = titleToNumber(columnTitle);
    cout << result << endl;
    return 0;
}
