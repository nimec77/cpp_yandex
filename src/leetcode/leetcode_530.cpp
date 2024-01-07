#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getMinimumDifference(TreeNode *root) {
    vector<int> nums;
    function<void(TreeNode *)> inorder = [&](TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        nums.push_back(node->val);
        inorder(node->right);
    };
    inorder(root);
    int res = INT_MAX;
    for (int i = 1; i < nums.size(); ++i) {
        res = min(res, nums[i] - nums[i - 1]);
    }
    return res;
}

int main() {
    return 0;
}