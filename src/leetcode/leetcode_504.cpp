#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string convertToBase7(int num) {
    if (num == 0) return "0";
    string res;
    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }
    while (num > 0) {
        res += to_string(num % 7);
        num /= 7;
    }
    reverse(res.begin(), res.end());
    return isNegative ? "-" + res : res;
}

int main() {
    return 0;
}