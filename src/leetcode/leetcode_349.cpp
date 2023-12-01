#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    unordered_set<int> res;

    for (auto x: nums2) {
        if (s.find(x) != s.end()) {
            res.insert(x);
        }
    }

    return {res.begin(), res.end()};
}

vector<int> intersection2(vector<int> nums1, vector<int> nums2) {
    int digits[1000] = {0};
    for (int x : nums1) {
        if (digits[x] == 0) {
            digits[x] = 1;
        }
    }
    vector<int> ans;
    for (int x : nums2) {
        if (digits[x] == 1) {
            ans.push_back(x);
            digits[x] = 0;
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
