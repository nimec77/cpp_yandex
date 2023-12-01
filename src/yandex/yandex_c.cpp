#include <iostream>
#include <vector>

using namespace std;


long long getNumberOfGoodPairs(int n, const vector<int>& numbers) {
    // your code goes here
    vector<int> modules_vector(n);
    for (int i = 0; i < n; i++) {
        modules_vector[i] = numbers[i] % 200;
    }
    vector<int> modules_count(200, 0);
    for (int i = 0; i < n; i++) {
        modules_count[modules_vector[i]]++;
    }
    long long result = 0;
    for (int i = 0; i < 200; i++) {
        result += (long long)modules_count[i] * (modules_count[i] - 1) / 2;
    }

    return result;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    int n = readInt();
    vector<int> numbers = readList(n);
    cout << getNumberOfGoodPairs(n, numbers);
}