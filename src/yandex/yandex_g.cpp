#include <vector>
#include <iostream>


using namespace std;

struct Node {
    int w;
    bool isRoot;

    vector<Node *> children;

    Node(bool isRoot, int w) {
        this->isRoot = isRoot;
        this->w = w;
        children = vector<Node *>();
    }
};

struct Vertex {
    int w;
    int p;

    Vertex(int w, int p) {
        this->w = w;
        this->p = p;
    }
};


class CalcPaths {
private:
    int pathsCount_ = 0;
    unsigned long n;
    int x;
    vector<Node *> nodes;

public:
    CalcPaths(unsigned long n, int x) {
        this->n = n;
        this->x = x;
        nodes = vector<Node *>(n);
    }

    [[nodiscard]] int pathsCount() const {
        return pathsCount_;
    }

    Node *createTree(vector<Vertex> tree) {
        for (int i = 0; i < n; i++) {
            auto parent = tree[i].p;
            nodes[i] = new Node(parent == -1, tree[i].w);
        }
        for (int i = 0; i < n; i++) {
            auto parent = tree[i].p;
            if (parent != -1) {
                nodes[parent]->children.push_back(nodes[i]);
            }
        }

        return nodes.front();
    }

    void dfs(Node *node, vector<int> weights) {
        auto sum = node->w;
        if (!node->isRoot && sum == x) {
            pathsCount_++;
        }
        auto it = weights.end();
        while (it != weights.begin()) {
            --it;
            sum += *it;
            if (sum == x) {
                pathsCount_++;
            }
        }
        if (node->children.empty()) {
            return;
        }
        weights.push_back(node->w);
        for (auto child: node->children) {
            dfs(child, weights);
        }
    }
};

int getNumberOfUpgoingPaths(const vector<Vertex> &tree, int x) {
    CalcPaths calcPaths(tree.size(), x);
    auto root = calcPaths.createTree(tree);
    calcPaths.dfs(root, vector<int>());

    return calcPaths.pathsCount();
}

vector<Vertex> readTree(int n) {
    vector<Vertex> tree;
    for (int i = 0; i < n; i++) {
        int parent, weight;
        cin >> parent >> weight;
        tree.emplace_back(weight, parent);
    }
    return tree;
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<Vertex> tree = readTree(n);
    cout << getNumberOfUpgoingPaths(tree, x);

}