#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int countNodes(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    auto left = root;
    auto right = root;
    int leftHeight = 0;
    int rightHeight = 0;

    while (left != nullptr) {
        left = left->left;
        leftHeight++;
    }

    while (right != nullptr) {
        right = right->right;
        rightHeight++;
    }

    if (leftHeight == rightHeight) {
        return (1 << leftHeight) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    return 0;
}
