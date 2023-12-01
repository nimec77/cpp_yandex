#include <vector>
#include <string>


std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result;
    for (const std::string& token : tokens) {
        if (!result.empty()) {
            result += delimiter;
        }
        result += token;
    }
    return result;
}
