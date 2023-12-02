#include <vector>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        string s;
        if (i % 3 == 0) {
            s += "Fizz";
        }
        if (i % 5 == 0) {
            s += "Buzz";
        }
        if (s == "") {
            s += to_string(i);
        }
        result.push_back(s);
    }
    return result;
}

int main() {
}
