#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        auto x = nums[i];
        auto it = map.find(x);
        if (it != map.end()) {
            if (abs(i - it->second) <= k) {
                return true;
            }
        }
        map[x] = i;
    }

    return false;
}

int main() {
    auto nums = inputArray();
    int k;
    cin >> k;
    auto res = containsNearbyDuplicate(nums, k);
    cout << res << endl;

    return 0;
}
