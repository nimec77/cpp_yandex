#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int32_t isqrt(int32_t n) {
    int32_t x = n;
    int32_t c = 0;

    int32_t d = 1 << 30;

    while (d > n) {
        d >>= 2;
    }

    while (d != 0) {
        if (x >= c + d) {
            x -= c + d;
            c = (c >> 1) + d;
        } else {
            c >>= 1;
        }
        d >>= 2;
    }
    return c;
}

bool isPerfectSquare(int num) {
    int x = isqrt(num);
    return x * x == num;
}

int main() {
    int num;
    cin >> num;
    cout << isPerfectSquare(num) << endl;
    return 0;
}
