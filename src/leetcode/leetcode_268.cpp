#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums) {
    int res = nums.size();

    for (int i = 0; i < nums.size(); i++) {
        res += i - nums[i];
    }
    return res;
}


int main() {
    return 0;
}
