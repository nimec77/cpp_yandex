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

int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main() {
    vector<int> nums = inputArray();
    int val;
    cin >> val;
    int len = removeElement(nums, val);
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
