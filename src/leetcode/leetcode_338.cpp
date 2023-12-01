#include <iostream>

using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    auto offset = 1;
    for (int i = 1; i <= n; i++) {
        if (offset * 2 == i) {
            offset = i;
        }
        dp[i] = 1 + dp[i - offset];
    }
    return dp;
}


int main() {
    int n;
    cin >> n;
    vector<int> bits = countBits(n);
    for (int i = 0; i <= n; i++) {
        cout << bits[i] << " ";
    }
    return 0;
}
