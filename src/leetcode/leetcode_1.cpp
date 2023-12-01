#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (m.find(complement) != m.end()) {
            result.push_back(m[complement]);
            result.push_back(i);
            return result;
        }
        m[nums[i]] = i;
    }
    return result;
}

int main() {
    vector<int> a = inputArray();
    int target;
    cin >> target;
    auto result = twoSum(a, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
//
// Created by Dmitry Seloustev on 04.11.2023.
//
