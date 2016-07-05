//
// Created by Guo Jing on 16/7/5.
//

#include "Solution.h"

int Solution::maxArea(std::vector<int> &height) {
    int size = (int)height.size();
    int max = 0;
    int area = 0;
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int width = end - start;
        if (height[start] > height[end]) {
            area = height[end] * width;
            end--;
        } else {
            area = height[start] * width;
            start++;
        }

        if (area > max) {
            max = area;
        }
    }
    return max;
}