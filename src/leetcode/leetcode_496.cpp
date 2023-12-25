#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < nums2.size(); ++i) {
        m[nums2[i]] = i;
    }
    for (int i : nums1) {
        int j = m[i];
        for (; j < nums2.size(); ++j) {
            if (nums2[j] > i) {
                res.push_back(nums2[j]);
                break;
            }
        }
        if (j == nums2.size()) {
            res.push_back(-1);
        }
    }
    return res;
}

int main() {
}