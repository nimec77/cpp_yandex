#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int total = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < timeSeries.size(); i++) {
        if (timeSeries[i] > end) {
            total += end - start;
            start = timeSeries[i];
            end = timeSeries[i] + duration;
        } else {
            end = timeSeries[i] + duration;
        }
    }
    total += end - start;
    return total;
}

int main() {
}