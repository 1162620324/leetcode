#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int finMin(vector<int>& nums){
    int left = 0, right = nums.size()-1;
    int mid;

    while(left < right){
        mid = (left+right)/2;
        if(nums[mid] < nums[right]){
            right = mid;
        }
        else if(nums[mid] > nums[right]){
            left = mid + 1;
        }
        else{
            if(nums[right] < nums[left]){
                right = mid;
            }
            else if(nums[right] > nums[left]){
                return nums[left];
            }
            else if(nums[right] == nums[left]){
                int i = left + 1;
                while(i < right && nums[i] == nums[left]){
                    i++;
                }
                if(i == right) return nums[right];
                if(nums[i] > nums[left]){
                    right = mid;
                }
                else if(nums[i] < nums[left]){
                    return nums[i];
                }
            }
        }

    }
    return nums[right];
}
  
//              **
//                      
// **  ** ** **               **
//                    **  **
//                 **
//
// l          m           r-1 r
//                         ^  |                             
//                         |__|
//当数组的最有值和中间值相等时，不能确定最小值在右半部分还是左半部分，
//但是可以确定的是最右值可以被排除是最小值的可能（当然如果整个数组所
//有元素相等时它的值可以时最小值，但返回具体的元素可以不是它）
 
int finMin(vector<int>& nums){
    int left = 0, right = nums.size()-1;
    int mid;

    while(left < right){
        mid = (left+right)/2;
        if(nums[mid] < nums[right]){
            right = mid;
        }
        else if(nums[mid] > nums[right]){
            left = mid + 1;
        }
        else{
            right -= 1;
        }

    }
    return nums[right];
}

int main(){

}