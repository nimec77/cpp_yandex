#include <iostream>
#include <string>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

int singleNumber(vector<int> &nums) {
    int result = 0;
    for (int x: nums) {
        result ^= x;
    }
    return result;
}

int main() {
    auto nums = inputArray();
    auto result = singleNumber(nums);
    cout << result << endl;
    return 0;
}
