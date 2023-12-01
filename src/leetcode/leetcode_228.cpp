#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

vector<string> summaryRanges(vector<int> nums) {
    vector<string> res;
    int n = nums.size();
    if (n == 0) {
        return res;
    }
    int a = nums[0];
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || nums[i] != nums[i + 1] - 1) {
            if (a == nums[i]) {
                res.push_back(to_string(a));
            } else {
                res.push_back(to_string(a) + "->" + to_string(nums[i]));
            }
            if (i != n - 1) {
                a = nums[i + 1];
            }
        }
    }
    return res;
}

int main() {
    auto nuns = inputArray();
    auto res = summaryRanges(nuns);
    for (const auto &x: res) {
        cout << x << " ";
    }
    return 0;
}
