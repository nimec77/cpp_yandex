#include <iostream>
#include <vector>

using namespace std;

bool isUgly(int n) {
    const vector<int> primes = {2, 3, 5};

    if (n <= 0) {
        return false;
    }

    for (int prime: primes) {
        while (n % prime == 0) {
            n /= prime;
        }
        if (n == 1) {
            return true;
        }
    }

    return n == 1;
}

int main() {
    int n;
    cin >> n;
    cout << isUgly(n) << endl;
    return 0;
}
