#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int rob(vector<int> &nums){
    if(nums.empty()) return 0;

    int len = nums.size();
    if(len == 1) return nums[0];
    
    int first = nums[0], second = max(nums[0], nums[1]);

    for(int i = 2; i < len; i++){
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}

int main(){

}