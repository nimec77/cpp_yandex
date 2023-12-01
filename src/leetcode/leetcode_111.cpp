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

int result = INT_MAX;

void dfs(TreeNode *root, int depth) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        result = min(result, depth + 1);
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

int minDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    dfs(root, 0);

    return result;
}

int main() {
    return 0;
}
