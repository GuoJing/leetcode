#include <iostream>
#include <chrono>
#include "Solution.h"

using namespace std;
using namespace std::chrono;

void print_vector(vector<vector<int>> ret){
    cout << "----------------------------------" << endl;
    for (vector<vector<int>>::size_type i = 0; i < ret.size(); i++) {
        for (vector<int>::size_type j=0; j < ret[i].size(); j++){
            cout << ret[i][j] << ',';
        }
        cout << endl;
    }

    cout << "total: " << ret.size() << endl;
}

void print_time(Solution *s, vector<int> nums) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    s->threeSum1(nums);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << duration << endl;
}

int main() {
    Solution *s = new Solution();
    vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,
                        -14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,
                        4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,
                        -4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,
                        10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};


    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    vector<vector<int>> ret1 = s->threeSum1(nums);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    vector<vector<int>> ret2 = s->threeSum2(nums);
    high_resolution_clock::time_point t4 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>( t2 - t1 ).count();
    auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();

    cout << duration1 << ',' << duration2 << endl;

    //print_vector(ret1);
    //print_vector(ret2);
    return 0;
}