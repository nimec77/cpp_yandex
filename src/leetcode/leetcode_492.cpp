#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<int> constructRectangle(int area) {
    int w = sqrt(area);
    while (area % w != 0) {
        w--;
    }
    return {area / w, w};
}

int main() {
}