#include <string>
#include <iterator>
#include <vector>

using namespace std;

string licenseKeyFormatting(string s, int k) {
    string res;
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != '-') {
            res += toupper(s[i]);
            if (++cnt % k == 0) res += '-';
        }
    }
    reverse(res.begin(), res.end());
    if (res.size() > 0 && res[0] == '-') res.erase(res.begin());
    return res;
}

int main() {

}