#include <vector>
#include <iostream>
#include <array>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

int thirdMax(vector<int> &nums) {
    vector<int> maxs;

    for (auto x: nums) {
        for (size_t i = 0; i < 3; i++) {
            if (i >= maxs.size()) {
                maxs.push_back(x);
                break;
            } else if (x == maxs[i]) {
                break;
            }
            if (x > maxs[i]) {
                swap(x, maxs[i]);
            }
        }
    }

    return maxs.size() < 3 ? maxs.front() : maxs.back();

}

int main() {
    auto nums = inputArray();
    cout << thirdMax(nums) << endl;
}
