#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

TreeNode *buildTree(vector<int> &nums, int &index) {
    if (index >= nums.size() || nums[index] == -1) {
        index++;
        return nullptr;
    }
    auto *root = new TreeNode(nums[index++]);
    root->left = buildTree(nums, index);
    root->right = buildTree(nums, index);
    return root;
}

string serialize(TreeNode *root) {
    if (root == nullptr) {
        return "-1";
    }
    stringstream ss;
    ss << root->val << " ";
    ss << serialize(root->left) << " ";
    ss << serialize(root->right) << " ";

    return ss.str();
}

TreeNode *deserialize(const string& data) {
    stringstream ss(data);
    vector<int> nums;
    int x;
    while (ss >> x) {
        nums.push_back(x);
    }
    int index = 0;
    return buildTree(nums, index);
}

int main() {
    auto *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    auto s = serialize(root);
    cout << s << endl;
    auto *newRoot = deserialize(s);
    return 0;
}