#include <iostream>

using namespace std;

bool isBadVersion(int n) {
    if (n >= 4) {
        return true;
    }
    return false;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    cin >> n;
    cout << firstBadVersion(n) << endl;
    return 0;
}
