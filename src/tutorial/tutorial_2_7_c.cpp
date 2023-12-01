#include <vector>
#include <string>


std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string token;
    for (char ch : str) {
        if (ch == delimiter) {
            result.push_back(token);
            token.clear();
        } else {
            token += ch;
        }
    }
    result.push_back(token);

    return result;
}
