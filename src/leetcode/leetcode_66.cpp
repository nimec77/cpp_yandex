#include <iostream>
#include <vector>

using namespace std;

vector<int> inputArray() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (carry == 0) {
            break;
        }
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}

vector<int> plusOne2(vector<int>& v) {
    int n = v.size();
    for(int i = n-1; i >= 0; i--){
        if(i == n-1)
            v[i]++;
        if(v[i] == 10){
            v[i] = 0;
            if(i != 0){
                v[i-1]++;
            }
            else{
                v.push_back(0);
                v[i] = 1;
            }
        }
    }
    return v;
}

int main() {
    vector<int> digits = inputArray();
    vector<int> result = plusOne2(digits);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
