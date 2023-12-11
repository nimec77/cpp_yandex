#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

void MakeTrain() {
    std::deque<int> train;
    std::string input;
    int car;
    size_t n;
    while (std::cin >> input) {
        if (input == "+left") {
            std::cin >> car;
            train.push_front(car);
        } else if (input == "+right") {
            std::cin >> car;
            train.push_back(car);
        } else if (input == "-left") {
            std::cin >> n;
            n = std::min(n, train.size());
            train.erase(train.begin(), train.begin() + n);
        } else if (input == "-right") {
            std::cin >> n;
            n = std::min(n, train.size());
            train.erase(train.end() - n, train.end());
        }
    }
    for (const auto &item: train) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    return 0;
}
