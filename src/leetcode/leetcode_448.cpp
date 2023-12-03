#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> res;
    unordered_set<int> s(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size(); i++) {
        if (s.find(i) == s.end()) {
            res.push_back(i);
        }
    }

    return res;
}

vector<int> findDisappearedNumbers2(vector<int> &nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            res.push_back(i + 1);
        }
    }

    return res;
}

int main() {
    return 0;
}