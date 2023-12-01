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

TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
        return root;
    }

    auto left = invertTree(root->left);
    auto right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int main() {
    return 0;
}
