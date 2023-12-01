//
// Created by Dmitry Seloustev on 10.11.2023.
//

#ifndef CPP_YANDEX_LEETCODE_225_H
#define CPP_YANDEX_LEETCODE_225_H

#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> in;
    queue<int> out;
public:
    MyStack() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (out.empty()) {
            while (in.size() > 1) {
                out.push(in.front());
                in.pop();
            }
            int res = in.front();
            in.pop();
            swap(in, out);
            return res;
        } else {
            int res = out.front();
            out.pop();
            return res;
        }
    }

    int top() {
        if (out.empty()) {
            while (in.size() > 1) {
                out.push(in.front());
                in.pop();
            }
            int res = in.front();
            in.pop();
            out.push(res);
            swap(in, out);
            return res;
        } else {
            return out.front();
        }
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};


#endif //CPP_YANDEX_LEETCODE_225_H
