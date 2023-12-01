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

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p == nullptr || q == nullptr) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->right, q->left) && isSameTree(p->left, q->right);
}

bool isSymmetric(TreeNode *root) {
    return isSameTree(root->left, root->right);
}

int main() {
    auto *p = new TreeNode(2);
    p->left = new TreeNode(3);
    p->right = new TreeNode(4);
    auto q = new TreeNode(2);
    q->left = new TreeNode(4);
    q->right = new TreeNode(3);
    auto root = new TreeNode(1);
    root->left = p;
    root->right = q;
    cout << isSymmetric(root) << endl;
    return 0;
}
