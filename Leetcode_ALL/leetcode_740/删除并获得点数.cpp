#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int rob(vector<int> & nums){
    int size = nums.size();
    int first = nums[0], second = max(nums[0], nums[1]);

    for(int i = 2; i < size; i++){
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}

int deleteAndEarn(vector<int>& nums){
    int n = nums.size();
    int maxVal = 0;
    for(int val: nums){
        maxVal = max(maxVal, val);
    }
    vector<int> sum(maxVal+1);
    for(int val: nums){
        sum[val] += val;
    }

    return rob(sum);
}

int main(){

}