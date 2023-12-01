#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool canWinNim(int n) {
    return n % 4 != 0;
}

bool helper(int n, unordered_map<int, bool> &memo) {
    if (memo.count(n) > 0) {
        return memo[n];
    }
    if (n <= 3) {
        memo[n] = true;
        return memo[n];
    }

    if (n == 4) {
        memo[n] = false;
        return memo[n];
    }

    memo[n] = !helper(n - 1, memo) != !helper(n - 2, memo) != !helper(n - 3, memo);
    return memo[n];
}

bool canWinNim2(int n) {
    unordered_map<int, bool> memo;
    return helper(n, memo);
}

int main() {
    int n;
    cin >> n;
    cout << canWinNim2(n) << endl;
    return 0;
}
