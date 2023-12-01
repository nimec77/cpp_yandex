#include <vector>
#include <iostream>
#include <utility>

std::vector<std::pair<int, int>> inputCoordinates(int n) {
    std::vector<std::pair<int, int>> coordinates;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        coordinates.emplace_back(x, y);
    }
    return coordinates;
}

std::vector<std::pair<int, int>> sortCoordinates(std::vector<std::pair<int, int>> coordinates) {
    std::sort(coordinates.begin(), coordinates.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
    });
    return coordinates;
}

int main() {
    int n;
    std::cin >> n;
    auto coordinates = inputCoordinates(n);
    coordinates = sortCoordinates(coordinates);
    for (auto coordinate : coordinates) {
        std::cout << coordinate.first << " " << coordinate.second << std::endl;
    }
    return 0;
}
