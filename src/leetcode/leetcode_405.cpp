#include <iostream>
#include <vector>
#include <string>
#include <bitset>


using namespace std;

string intToHex(int num) {
    if (num == 0) {
        return "0";
    }
    string res;
    unsigned num2 = num;
    while (num2 != 0) {
        int tmp = num2 & 15;
        if (tmp < 10) {
            res += tmp + '0';
        } else {
            res += tmp - 10 + 'a';
        }
        num2 >>= 4;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int num;
    cin >> num;
    cout << intToHex(num) << endl;
    return 0;
}
