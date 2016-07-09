//
// Created by Guo Jing on 16/7/9.
//

#include "Solution.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int Solution::threeSumClosest(vector<int> &nums, int target) {
    // sort the numbers
    sort(nums.begin(), nums.end());

    int total = (int)nums.size();

    int i = 0;

    int result = nums[0] + nums[1] + nums[2];

    while ( i < total ){
        int j = i + 1;
        int k = total - 1;

        while ( j < k ){
            int x = nums[i];
            int y = nums[j];
            int z = nums[k];
            int sum = x + y + z;

            int tmp = abs(result - target);
            int cur = abs(sum - target);

            if (tmp > cur) {
                result = sum;
            }

            if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
        i++;
    }

    return  result;
}