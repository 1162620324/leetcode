#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int removeElement(vector<int> &nums, int val){
    for(auto iter = nums.begin(); iter != nums.end(); ){
        if(*iter == val){
            iter = nums.erase(iter);
        }
        else{
            iter++;
        }
    }
    return nums.size();
}

    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }


int main(){

}