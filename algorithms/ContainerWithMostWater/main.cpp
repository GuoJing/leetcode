#include <iostream>
#include <vector>
#include "Solution.h"

// https://leetcode.com/problems/container-with-most-water/

using namespace std;

int main() {
    Solution *s = new Solution();
    vector<int> *vec = new vector<int>;

    for (int i=1; i<5; i++) {
        vec->push_back(i);
    }

    int max = s->maxArea(*vec);
    cout << max << endl;
    delete s;
    return 0;
}