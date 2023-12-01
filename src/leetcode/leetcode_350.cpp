#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
    unordered_map<int, int> digits;
    for (int x: nums1) {
        digits[x]++;
    }
    vector<int> ans;
    for (int x: nums2) {
        auto it = digits.find(x);
        if (it != digits.end() && it->second > 0) {
            ans.push_back(x);
            it->second--;
        }
    }

    return ans;
}

int main() {
    vector<int> nums1 = inputArray();
    vector<int> nums2 = inputArray();
    vector<int> res = intersection(nums1, nums2);
    for (auto x: res) cout << x << " ";
    return 0;
}
