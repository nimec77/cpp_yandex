#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

vector<int> inputArray() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}


int main() {
    vector<int> nums = inputArray();
    int n = removeDuplicates(nums);
    cout << n << endl;
    return 0;
}
