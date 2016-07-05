#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution *s = new Solution();
    int a = 454;
    bool r = s->isPalindrome(a);
    cout << r << endl;
    return 0;
}