#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        auto bit = (n >> i) & 1;
        res |= bit << (31 - i);
    }

    return res;
}

int main() {
    uint32_t n;
    cin >> n;
    auto res = reverseBits(n);
    cout << res << endl;
    return 0;
}
