#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        if (((n >> i) & 1) == 1) {
            res++;
        }
    }

    return res;
}

int hammingWeight2(uint32_t n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }

    return count;
}

int main() {
    uint32_t n;
    cin >> n;
    auto res = hammingWeight2(n);
    cout << res << endl;
    return 0;
}
