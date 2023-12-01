#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long getCardCount(int n, int k, const vector<long long> &cards) {
    // your code goes here
    // Если количество карт и попыток равно то возвращаем сумму
    if (n == k) {
        long long sum = 0;
        for (auto &i: cards) {
            sum += i;
        }
        return sum;
    }
    vector<long long> right_vector;
    vector<long long> left_vector;
    long long right_sum = 0;
    long long left_sum = 0;
    for (int i = 0; i < k; i++) {
        right_sum += cards[n - i - 1];
        right_vector.push_back(right_sum);
        left_sum += cards[i];
        left_vector.push_back(left_sum);
    }
    long long max_sum = 0;
    for (int i = 0; i <= k; i++) {
        long long sum;
        if (i == 0) {
            sum = right_vector[k - 1];
        } else if (i == k) {
            sum = left_vector[i - 1];
        } else {
            sum = left_vector[i - 1] + right_vector[k - i - 1];
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    return max_sum;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<long long> readList(int n) {
    vector<long long> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    int n = readInt();
    int k = readInt();
    vector<long long> cards = readList(n);
    cout << getCardCount(n, k, cards);
}

