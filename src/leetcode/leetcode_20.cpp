#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<char, char> bracketsMap{
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
};


bool isValid(string s ) {
    stack<char> st;
    for (auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if (c != bracketsMap[top]) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string brackets;
    cin >> brackets;
    cout << isValid(brackets) << endl;
    return 0;
}
//
// Created by Dmitry Seloustev on 05.11.2023.
//
