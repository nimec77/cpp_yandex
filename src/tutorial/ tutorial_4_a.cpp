#include <iostream>
#include <cctype>
#include <string>
#include <unordered_set>


using namespace std;

bool isStrongPassword(string &password) {
    unordered_set<int> strongSet(4);
    if (password.length() < 8) {
        return false;
    }
    if (password.length() > 14) {
        return false;
    }
    for (char c: password) {
        if (isdigit(c)) {
            strongSet.insert(1);
        } else if (islower(c)) {
            strongSet.insert(2);
        } else if (isupper(c)) {
            strongSet.insert(3);
        } else if (!isalnum(c)) {
            strongSet.insert(4);
        }

        if (strongSet.size() >= 3) {
            return true;
        }
    }

    return false;
}


int main() {
    string password;
    cin >> password;
    cout << (isStrongPassword(password) ? "YES" : "NO") << endl;
    return 0;
}
