#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int res;
    int prev = 0;
    int curr = 1;
    for (int i = 2; i <= n; i++) {
        res = prev + curr;
        prev = curr;
        curr = res;
    }
    return res;
}

int main() {
    return 0;
}