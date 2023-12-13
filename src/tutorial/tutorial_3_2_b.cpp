#include <iostream>
#include <map>
#include <unordered_set>
#include <string>

int main() {
    std::map<char, int> counter;
    std::string word;
    int wordCount = 0;

    while (std::cin >> word) {
        ++wordCount;
        std::unordered_set<char> letters{word.begin(), word.end()};
        for (char c : letters) {
            ++counter[c];
        }
    }
    for (auto [c, freq] : counter) {
        if (freq == wordCount) {
            std::cout << c;
        }
    }
    std::cout << std::endl;
    return 0;
}
