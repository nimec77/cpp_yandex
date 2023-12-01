#include <iostream>
#include <map>

using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

map<int, int> memo;

int climbStairs2(int n) {
    if (n <= 0) return 0;
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (memo.count(n) == 0) {
        memo[n] = climbStairs2(n - 1) + climbStairs2(n - 2);
    }
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    cout << climbStairs2(n) << endl;
    return 0;
}
