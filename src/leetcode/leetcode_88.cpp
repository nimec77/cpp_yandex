#include <iostream>
#include <vector>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    return a;
}

void moveElements(vector<int> &nums1, int n, int k) {
    for (int i = k - 1; i >= n; i--) {
        nums1[i + 1] = nums1[i];
    }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = 0, j = 0, k = m;
    while (j < n && i < k) {
        if (nums1[i] <= nums2[j]) {
            i++;
        } else {
            moveElements(nums1, i, k);
            k++;
            nums1[i] = nums2[j];
            j++;
            i++;
        }
    }
    while (j < n) {
        nums1[i] = nums2[j];
        j++;
        i++;
    }
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0 && i >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = inputArray();
    vector<int> nums2 = inputArray();
    int m = nums1.size();
    nums1.resize(nums1.size() + nums2.size(), 0);
    merge(nums1, m, nums2, nums2.size());
    for (int i: nums1) {
        cout << i << " ";
    }
    return 0;
}
