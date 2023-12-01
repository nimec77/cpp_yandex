#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> inputArray() {
    vector<string> arr;
    ifstream input1;
    input1.open("input.txt");
    string s;
    while (getline(input1, s)) {
        arr.push_back(s);
    }

    return arr;
}

int main() {
    vector<string> arr = inputArray();
    sort(arr.rbegin(), arr.rend());
    for (const string& s : arr) {
        cout << s << endl;
    }
    return 0;
}
