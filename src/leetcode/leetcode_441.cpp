#include <vector>
#include <iostream>
#include <array>
#include <cmath>

using namespace std;

int arrangeCoins(int n) {
    double sn = n;
    auto d = 8 * sn + 1;
    auto x = (sqrt(d) - 1) / 2;

    return (int)x;
}

int main() {
    int n;
    cin >> n;
    cout << arrangeCoins(n) << endl;
}
