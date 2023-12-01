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

TreeNode *inputTree() {
    int n;
    cin >> n;
    vector<TreeNode *> nodes(n);
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

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    auto *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);
    auto q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);
    cout << isSameTree(p, q) << endl;
    return 0;
}
