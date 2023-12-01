#include <iostream>
#include <vector>

using namespace std;

vector<int> inputArray(int n) {
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

vector<int> guestsPlaces(int n, vector<int> &places) {
    vector<int> guests(n, 0);
    for (size_t guest = 0; guest < places.size(); guest++) {
        auto place = places[guest];
        guests[place - 1] = guest + 1;
    }
    return guests;
}

int main() {
    int n;
    cin >> n;
    vector<int> places = inputArray(n);
    vector<int> guests = guestsPlaces(n, places);
    for (auto x: guests) cout << x << ' ';
    return 0;
}
