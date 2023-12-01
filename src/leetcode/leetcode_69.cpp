#include <iostream>

using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0;
    int left = 1, right = x, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
    return 0;
}
