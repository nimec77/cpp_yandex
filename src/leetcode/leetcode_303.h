//
// Created by Dmitry Seloustev on 16.11.2023.
//

#ifndef CPP_YANDEX_LEETCODE_303_H
#define CPP_YANDEX_LEETCODE_303_H

#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        sum = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};


#endif //CPP_YANDEX_LEETCODE_303_H
