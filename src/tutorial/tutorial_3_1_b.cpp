#include <iostream>
#include <deque>
#include <string>

std::deque<std::string> inputQueue(size_t n) {
    std::deque<std::string> q;
    std::string name, direction;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> name >> direction;
        if (direction == "top") {
            q.push_front(name);
        } else {
            q.push_back(name);
        }
    }

    return q;
}

int main() {
    size_t n;
    std::cin >> n;
    auto q = inputQueue(n);
    size_t m;
    std::cin >> m;
    size_t x;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> x;
        std::cout << q[x - 1] << "\n";
    }
    return 0;
}