#include <iostream>
#include <string>
#include <sstream>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

string convert(vector<int> &nums) {
    stringstream ss;
    int l = 0;
    int r = 0;

    int cur;
    int next;
    while (r < nums.size()) {
        cur = nums[r];
        if (r < nums.size() - 1) {
            next = nums[r + 1];
        } else {
            next = cur;
        }
        if (cur != next - 1) {
            if (l != r) {
                ss << nums[l] << "-" << nums[r];
            } else {
                ss << nums[l];
            }
            if (r < nums.size() - 1) {
                ss << ",";
            }
            r++;
            l = r;
        } else {
            r++;
        }
    }

    return ss.str();
}

int main() {
    auto nums = inputArray();
    auto result = convert(nums);
    cout << result << endl;
    return 0;
}
