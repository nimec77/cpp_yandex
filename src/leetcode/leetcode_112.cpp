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

int target;

struct SumInfo {
    bool hasPathSum;
    int sum;

    SumInfo(bool hasPathSum, int sum) : hasPathSum(hasPathSum), sum(sum) {}
};

SumInfo dfs(TreeNode *root, SumInfo info) {
    if (root == nullptr) {
        return {false, info.sum};
    }
    if (root->left == nullptr && root->right == nullptr) {
        auto sum = info.sum + root->val;
        return {sum == target, sum};
    }

    auto left = dfs(root->left, {false, info.sum + root->val});
    if (left.hasPathSum) {
        return left;
    }
    auto right = dfs(root->right, {false, info.sum + root->val});
    return right;
}

bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == targetSum && root->left == nullptr && root->right == nullptr) {
        return true;
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main() {
    return 0;
}
