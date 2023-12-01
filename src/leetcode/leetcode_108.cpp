#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

vector<int> a;

TreeNode *helper(int l, int r) {
    if (l > r) {
        return nullptr;
    }
    int m = (l + r) / 2;
    auto root = new TreeNode(a[m]);
    root->left = helper(l, m - 1);
    root->right = helper(m + 1, r);

    return root;
}


TreeNode *sortedArrayToBST(vector<int> &nums) {
    a = nums;
    return helper(0, nums.size() - 1);
}

int main() {
    auto nums = inputArray();
    auto bst = sortedArrayToBST(nums);
    cout << bst->val << endl;
    return 0;
}
