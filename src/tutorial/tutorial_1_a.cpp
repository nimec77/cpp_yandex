#include <iostream>

using namespace std;

int permutations(int n) {
    if (n == 1) {
        return 1;
    }
    return n * permutations(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << permutations(n) << endl;
    return 0;
}
