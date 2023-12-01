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

void dfs(TreeNode *root, string path, vector<string> &paths) {
    path += "->" + to_string(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        paths.push_back(path);
        return;
    }

    if (root->left != nullptr) {
        dfs(root->left, path, paths);
    }
    if (root->right != nullptr) {
        dfs(root->right, path, paths);
    }
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> paths;
    if (root == nullptr) {
        return paths;
    }
    if (root->left == nullptr && root->right == nullptr) {
        paths.push_back(to_string(root->val));
        return paths;
    }
    if (root->left != nullptr) {
        dfs(root->left, to_string(root->val), paths);
    }
    if (root->right != nullptr) {
        dfs(root->right, to_string(root->val), paths);
    }

    return paths;
}

int main() {
    return 0;
}
