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

int majorityElement(vector<int> &nums) {
    int result;
    int count = 0;
    for (auto x: nums) {
        if (count == 0) {
            result = x;
        }
        if (result == x) {
            count++;
        } else {
            count--;
        }
    }

    return result;
}

int main() {
    auto nums = inputArray();
    auto result = majorityElement(nums);
    cout << result << endl;
    return 0;
}
