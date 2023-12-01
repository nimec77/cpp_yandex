#include <iostream>
#include <cmath>

using namespace std;

double log4(int n) {
    return log(n) / log(4);
}

bool isPowerOfFour(int n) {
    auto res = log4(n);
    return n > 0 && res == floor(res);
}

int main() {
    int n;
    cin >> n;
    cout << isPowerOfFour(n) << endl;
    return 0;
}
