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

int postOrder(TreeNode *root, int &tilt) {
    if (root == nullptr) {
        return 0;
    }
    int left = postOrder(root->left, tilt);
    int right = postOrder(root->right, tilt);
    tilt += abs(left - right);
    return left + right + root->val;
}

int findTilt(TreeNode *root) {
    int tilt = 0;
    postOrder(root, tilt);
    return tilt;
}


int main() {
    return 0;
}