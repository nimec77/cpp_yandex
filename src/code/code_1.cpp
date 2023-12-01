#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            if (i * i != n) {
                a.push_back(n / i);
            }
        }
    }
    sort(a.begin(), a.end());
    for (auto x : a) {
        cout << x << endl;
    }
}
