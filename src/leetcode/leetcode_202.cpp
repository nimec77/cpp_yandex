#include <iostream>
#include <set>

using namespace std;

int calcSum(int n) {
    int sum = 0;

    while (n > 0) {
        auto digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    set<int> visit;

    while (visit.count(n) == 0) {
        visit.insert(n);
        n = calcSum(n);
        if (n == 1) {
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    auto res = isHappy(n);
    cout << res << endl;
    return 0;
}
