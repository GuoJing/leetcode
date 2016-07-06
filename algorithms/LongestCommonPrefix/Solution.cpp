//
// Created by Guo Jing on 16/7/6.
//

#include "Solution.h"

string Solution::longestCommonPrefix(vector<string> &strs) {
    if (strs.size()==0) {
        return "";
    }

    int len = (int)strs[0].size();

    for (int i=1; i < strs.size(); i++){
        for (int j=0; j < len; j++) {
            if (strs[i-1][j] != strs[i][j]) {
                if (j < len) {
                    len = j;
                }
                break;
            }
        }
    }
    return strs[0].substr(0, (unsigned long)len);
}