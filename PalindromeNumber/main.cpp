#include <iostream>
#include "Solution.h"

// https://leetcode.com/problems/palindrome-number/

using namespace std;

int main() {
    Solution *s = new Solution();
    int a = 454;
    bool r = s->isPalindrome(a);
    cout << r << endl;
    return 0;
}
