#include <iostream>
#include <sstream>

using namespace std;

string monthlyCalendar(int n, int k) {
    stringstream ss;

    int pos = 1;
    for (; pos < n; pos++) {
        ss << "  ";
        ss << " ";
    }
    for (int day = 1; day <= k; day++) {
        if (day < 10) {
            ss << " " << day;
        } else {
            ss << day;
        }
        if (pos % 7 == 0) {
            ss << "\n";
        } else {
            ss << " ";
        }
        pos++;
    }
    if ((pos - 1) % 7 != 0) {
        ss << "\n";
    }

    return ss.str();
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << monthlyCalendar(n, k);
    return 0;
}
