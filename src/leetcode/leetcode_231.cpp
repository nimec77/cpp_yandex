#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPowerOfTwo(int n) {
    long long m = n;
    return n > 0 & (m & (m - 1)) == 0;
}

int main() {
    int n;
    cin >> n;
    auto res = isPowerOfTwo(n);
    cout << res << endl;
    return 0;
}
