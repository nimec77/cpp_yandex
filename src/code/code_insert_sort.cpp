#include <vector>
#include <iostream>

using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

vector<int> insertSort(vector<int> a) {
    for (int i = 1; i < a.size(); i++) {
        auto j = i;
        while (a[j] < a[j - 1] && j > 0) {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
    return a;
}

int main() {
    vector<int> a = inputArray();

    a = insertSort(a);
    for (auto x: a) cout << x << " ";

    return 0;
}
