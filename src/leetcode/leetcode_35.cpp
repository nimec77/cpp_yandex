#include <iostream>
#include <vector>

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

int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    vector<int> arr = inputArray();
    int target;
    cin >> target;
    cout << searchInsert(arr, target) << endl;
    return 0;
}
