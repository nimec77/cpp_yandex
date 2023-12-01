#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* inputTree() {
    int n;
    cin >> n;
    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; ++i) {
        int val, left, right;
        cin >> val >> left >> right;
        nodes[i] = new TreeNode(val);
        if (left != -1) {
            nodes[i]->left = nodes[left];
        }
        if (right != -1) {
            nodes[i]->right = nodes[right];
        }
    }
    return nodes[0];
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    vector<TreeNode*> stack;
    TreeNode* cur = root;
    while (cur != nullptr || !stack.empty()) {
        while (cur != nullptr) {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back();
        stack.pop_back();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}

vector<int> result;

void inorderHelper(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    if (node->left != nullptr) {
        inorderHelper(node->left);
    }
    result.push_back(node->val);
    if (node->right != nullptr) {
        inorderHelper(node->right);
    }
}

int main() {
    TreeNode* root = inputTree();
    inorderHelper(root);
    return 0;
}
