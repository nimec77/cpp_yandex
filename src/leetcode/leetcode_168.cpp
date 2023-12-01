#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int columnNumber) {
    string result;
    while (columnNumber > 0) {
        int offset = (columnNumber - 1) % 26;
        result += char('A' + offset);
        columnNumber = (columnNumber - 1) / 26;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int n;
    cin >> n;
    auto result = convertToTitle(n);
    cout << result << endl;
    return 0;
}
