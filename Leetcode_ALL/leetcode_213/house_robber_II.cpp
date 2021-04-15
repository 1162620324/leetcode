#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int rob_helper(vector<int> & nums, int start, int end){
    int first = nums[start], second = max(nums[start], nums[start+1]);

    for(int i = start + 2; i <= end; i++){
        int temp = second;
        second = max(first+nums[i], second);
        first = temp;
    }
    return second;
}

int rob(vector<int> & nums){
    if(nums.empty()) return 0;

    int len = nums.size();
    if(len == 1) return nums[0];
    if(len == 2) return max(nums[0], nums[1]);

    return max(rob_helper(nums, 0, len - 2), rob_helper(nums, 1, len - 1));
}