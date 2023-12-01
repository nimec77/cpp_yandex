#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool PowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

int main() {
    int n;
    cin >> n;
    cout << PowerOfThree(n) << endl;
    return 0;
}
