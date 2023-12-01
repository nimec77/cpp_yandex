#include <iostream>

using namespace std;

int getSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int addDigits(int num) {
    if (num < 10) {
        return num;
    }

    auto res = num;
    do {
        res = getSum(res);
    } while (res >= 10);

    return res;
}

int addDigits2(int num) {
    if (num == 0) {
        return 0;
    }
    if (num % 9 == 0) {
        return 9;
    }

    return num % 9;
}

int main() {
    int num;
    cin >> num;
    cout << addDigits(num) << endl;
    return 0;
}
