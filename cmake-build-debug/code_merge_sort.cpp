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

vector<int> mergeArrays(vector<int> a, vector<int> b) {
    vector<int> c(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < a.size()) c[k++] = a[i++];
    while (j < b.size()) c[k++] = b[j++];
    return c;
}

vector<int> mergeSort(vector<int> a) {
    if (a.size() == 1) return a;
    vector<int> b(a.begin(), a.begin() + a.size() / 2);
    vector<int> c(a.begin() + a.size() / 2, a.end());
    return mergeArrays(mergeSort(b), mergeSort(c));
}

int main() {
    vector<int> a = inputArray();

    a = mergeSort(a);
    for (auto x: a) cout << x << " ";

    return 0;
}
