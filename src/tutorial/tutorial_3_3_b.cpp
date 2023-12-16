
template <typename Iter>

Iter Unique(Iter begin, Iter end) {
    if (begin == end) {
        return end;
    }
    Iter new_end = begin;
    for (Iter it = begin; it != end; ++it) {
        if (*new_end != *it) {
            ++new_end;
            *new_end = *it;
        }
    }
    return ++new_end;
}

int main() {
}
