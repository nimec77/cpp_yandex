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

struct Balance {
    bool isBalanced;
    int height;

    Balance(bool isBalanced, int height) : isBalanced(isBalanced), height(height) {};
};


Balance dfs(TreeNode *root) {
    if (root == nullptr) {
        return {true, 1};
    }
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    auto isBalanced = left.isBalanced && right.isBalanced && abs(left.height - right.height) <= 1;

    return {isBalanced, max(left.height, right.height) + 1};
}

int dfs2(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    auto left = dfs2(root->left);
    if (left == -1) {
        return -1;
    }

    auto right = dfs2(root->right);
    if (right == -1) {
        return -1;
    }

    if (abs(left - right) > 1) {
        return -1;
    }

    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root) {
    return dfs2(root) != -1;
}

int main() {
    return 0;
}
