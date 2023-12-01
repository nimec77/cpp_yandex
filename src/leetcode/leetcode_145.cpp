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

vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return result;
    }

    if (root->left != nullptr) {
        postorderTraversal(root->left);
    }
    if (root->right != nullptr) {
        postorderTraversal(root->right);
    }
    result.push_back(root->val);

    return result;
}

int main() {
    return 0;
}
