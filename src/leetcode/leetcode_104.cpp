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

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    auto *root = new TreeNode(3);
    root->left = new TreeNode(9);
    auto p = root->right = new TreeNode(20);
    p->left = new TreeNode(15);
    p->right = new TreeNode(7);

    cout << maxDepth(root) << endl;
    return 0;
}
