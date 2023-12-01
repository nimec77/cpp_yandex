#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    vector<char> result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry == 1) {
        carry += i >= 0 ? a[i--] - '0' : 0;
        carry += j >= 0 ? b[j--] - '0' : 0;
        result.push_back(char(carry % 2 + '0'));
        carry /= 2;
    }
    return {result.rbegin(), result.rend()};
}

int main() {
    string a;
    string b;
    cin >> a >> b;
    cout << addBinary(a, b) << endl;
    return 0;
}
