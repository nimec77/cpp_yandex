//
// Created by Dmitry Seloustev on 11.11.2023.
//

#ifndef CPP_YANDEX_LEETCODE_232_H
#define CPP_YANDEX_LEETCODE_232_H

#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> a;
    stack<int> b;

public:
    MyQueue() {
    }

    void push(int x) {
        a.push(x);
    }

    int pop() {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
        int res = b.top();
        b.pop();
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        return res;
    }

    int peek() {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
        int res = b.top();
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        return res;
    }

    bool empty() {
        return a.empty();
    }
};


#endif //CPP_YANDEX_LEETCODE_232_H
