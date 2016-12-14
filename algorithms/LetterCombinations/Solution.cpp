//
// Created by Guo Jing on 16/7/9.
//

#include "Solution.h"
#include <iostream>
#include <map>

using namespace std;

void dfs(const string &digits, size_t cur, string path, vector<string> &result) {
    const vector<string> keyboard { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    if (cur == digits.size()) {
        result.push_back(path);
        return;
    }
    for (auto c : keyboard[digits[cur] - '0']) {
        dfs(digits, cur + 1, path + c, result);
    }
}

vector<string> Solution::letterCombinations(string digits) {
    if (digits == "") return {};
    vector<string> result;
    dfs(digits, 0, "", result);
    return result;
}