#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}


int maxProfit(vector<int> &prices) {
    int profit = 0;
    int minIndex = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < prices[minIndex]) {
            minIndex = i;
        }
        auto maxValue = prices[i] - prices[minIndex];
        if (maxValue > profit) {
            profit = maxValue;
        }
    }
    return profit;
}

int main() {
    auto prices = inputArray();
    auto profit = maxProfit(prices);
    cout << profit << endl;
    return 0;
}
