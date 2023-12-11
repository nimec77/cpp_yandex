#include <iostream>
#include <string>
#include <list>


std::list<std::string> InputFile() {
    std::list<std::string> file;
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        file.push_back(line);
    }
    return file;
}


int main() {
    std::list<std::string> file = InputFile();

    auto cursor = file.begin();
    std::string command;
    std::string buffer;
    while (std::cin >> command) {
        if (command == "Up") {
            if (cursor == file.begin()) {
                continue;
            }
            --cursor;
        } else if (command == "Down") {
            if (cursor == file.end()) {
                continue;
            }
            ++cursor;
        } else if (command == "Ctrl+X") {
            if (cursor == file.end()) {
                continue;
            }
            buffer = std::move(*cursor);
            cursor = file.erase(cursor);
        } else if (command == "Ctrl+V") {
            if (buffer.empty()) {
                continue;
            }
            file.insert(cursor, buffer);
        }
    }
    for (auto &it: file) {
        std::cout << it << std::endl;
    }
    return 0;
}
