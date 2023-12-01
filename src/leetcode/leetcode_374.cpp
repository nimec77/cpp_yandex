#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int guess(int num) {
    if (num < 6) {
        return 1;
    } else if (num > 6) {
        return -1;
    }
    return 0;
}

int guessNumber(int n) {
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (guess(mid) == 0) {
            return mid;
        } else if (guess(mid) == 1) {
            left = mid + 1;
        } else if (guess(mid) == -1) {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    auto res = guessNumber(n);
    cout << res << endl;
    return 0;
}
