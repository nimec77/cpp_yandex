#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int findLUSLength(string a, string b) {
    if (a == b) return -1;
    return max(a.size(), b.size());
}

int main() {
    return 0;
}