#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main() {
    Solution *s = new Solution();
    vector<string> vec;
    vec.push_back("abcdef");
    vec.push_back("abc");
    vec.push_back("abcxxf");
    string ret = s->longestCommonPrefix(vec);
    cout << ret << endl;
    return 0;
}