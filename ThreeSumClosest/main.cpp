#include <iostream>
#include <vector>
#include "Solution.h"

// https://leetcode.com/problems/3sum-closest/

using namespace std;

int main() {
    int data[] = {-3, 0, 1, 2};
    int target = 1;
    vector<int> nums (data, data+4);

    Solution *s = new Solution();
    int ret = s->threeSumClosest(nums, target);
    cout << "result is " << ret << endl;
    return 0;
}