#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;
}

int main() {
    return 0;
}/
