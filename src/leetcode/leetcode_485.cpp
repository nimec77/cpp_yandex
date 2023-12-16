#include <string>
#include <iterator>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0, cnt = 0;
    for (int num : nums) {
        if (num == 1) {
            ++cnt;
            res = max(res, cnt);
        } else {
            cnt = 0;
        }
    }
    return res;
}

int main() {

}