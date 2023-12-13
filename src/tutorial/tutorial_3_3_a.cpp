#include <vector>
#include <algorithm>

template <typename T>
void Duplicate(std::vector<T>& v) {
    v.reserve(v.size() * 2);
    std::copy(v.begin(), v.end(), std::back_inserter(v));
}
