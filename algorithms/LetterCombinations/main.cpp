#include <iostream>
#include "Solution.h"

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// using DFS

using namespace std;

int main() {
    Solution *s = new Solution();
    string digits = "23";
    vector<string> ret = s->letterCombinations(digits);
    for (vector<string>::const_iterator i = ret.begin(); i != ret.end(); ++i){
        cout << *i;
    }
    cout << endl;
    return 0;
}