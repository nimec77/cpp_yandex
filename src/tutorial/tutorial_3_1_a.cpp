#include <iostream>
#include <string>
#include <vector>

template<typename Container>
void Print(const Container &data, const std::string &delimiter) {
    bool first = true;

    for (const auto &elem: data) {
        if (!first) {
            std::cout << delimiter;
        } else {
            first = false;
        }

        std::cout << elem;
    }

    std::cout << "\n";
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    Print(v, ", ");
    return 0;
}