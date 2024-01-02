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

void inorder(TreeNode *root, int &pre, int &count, int &maxCount, vector<int> &res) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, pre, count, maxCount, res);
    if (root->val == pre) {
        count++;
    } else {
        count = 1;
    }
    if (count == maxCount) {
        res.push_back(root->val);
    } else if (count > maxCount) {
        maxCount = count;
        res.clear();
        res.push_back(root->val);
    }
    pre = root->val;
    inorder(root->right, pre, count, maxCount, res);
}

vector<int> findMode(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    int maxCount = 0, count = 0, pre = INT_MIN;
    inorder(root, pre, count, maxCount, res);
    return res;
}

int main() {
    return 0;
}