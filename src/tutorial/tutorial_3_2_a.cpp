#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> s;
    int x;
    while (std::cin >> x) {
        if (s.contains(x)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
        s.insert(x);
    }
    return 0;
}
