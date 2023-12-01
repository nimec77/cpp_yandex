#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

bool  containsDuplicate(vector<int> &nums) {
    unordered_set<int> s;

    for (auto x: nums) {
        if (s.find(x) != s.end()) {
            return true;
        }
        s.insert(x);
    }
    return false;
}

int main() {
    auto nums = inputArray();
    return 0;
}
