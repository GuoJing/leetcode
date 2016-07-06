//
// Created by Guo Jing on 16/7/5.
//

#include <limits>
#include "Solution.h"

using namespace std;

bool Solution::isPalindrome(int x) {
    int b = 0;
    int c = x;

    while (c > 0){
        int i = c % 10;
        c = c / 10;
        b = b * 10 + i;
    }

    if (b > std::numeric_limits<int>::max()) {
        return false;
    }

    if (b < std::numeric_limits<int>::min()) {
        return false;
    }

    return b == x;
}