#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> result;

vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return result;
    }
    result.push_back(root->val);
    if (root->left != nullptr) {
        preorderTraversal(root->left);
    }
    if (root->right != nullptr) {
        preorderTraversal(root->right);
    }

    return result;
}

int main() {
    return 0;
}
