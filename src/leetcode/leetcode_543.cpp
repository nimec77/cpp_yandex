#include <vector>
#include <string>
#include <algorithm>
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


int diameterOfBinaryTree(TreeNode *root) {
    int res = 0;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    };
    dfs(root);
    return res;
}

int main() {
    return 0;
}