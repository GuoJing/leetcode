//
// Created by Guo Jing on 16/7/14.
//

#include <map>
#include <string>
#include <iostream>
#include "Solution.h"

using namespace std;

vector<vector<int>> Solution::threeSum1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    map<string, vector<int>> ht;
    int total = (int)nums.size();

    for (int i=0; i < total; i++) {
        int j = i + 1;
        int k = total - 1;

        while (j < k){
            int x = nums[i];
            int y = nums[j];
            int z = nums[k];

            if (x + y + z == 0) {
                vector<int> tmp = {x, y, z};
                string key = to_string(x) + to_string(y) + to_string(z);
                ht[key] = tmp;

                j++;
                k--;
            } else if (x + y + z < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    for( map<string, vector<int>>::iterator it = ht.begin(); it != ht.end(); ++it) {
        ret.push_back(it->second);
    }

    return ret;
}

vector<vector<int>> Solution::threeSum2(vector<int> &nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int total = (int)nums.size();

    for (int i=0; i < total; i++){
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int start = i + 1, end = nums.size() - 1;
        int target = -nums[i];
        while (start < end) {
            if (start > i + 1 && nums[start - 1] == nums[start]) {
                start++;
                continue;
            }
            if (nums[start] + nums[end] < target) {
                start++;
            } else if (nums[start] + nums[end] > target) {
                end--;
            } else {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[start]);
                tmp.push_back(nums[end]);
                ret.push_back(tmp);
                start++;
            }
        }
    }

    return ret;
}