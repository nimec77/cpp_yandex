#include <vector>
#include <string>


std::string CommonPrefix(const std::vector<std::string>& words) {
    std::string prefix;
    if (words.empty()) {
        return prefix;
    }
    for (size_t i = 0; i < words[0].size(); i++) {
        char c = words[0][i];
        for (size_t j = 1; j < words.size(); j++) {
            if (i >= words[j].size() || words[j][i] != c) {
                return prefix;
            }
        }
        prefix += c;
    }
    return prefix;
}