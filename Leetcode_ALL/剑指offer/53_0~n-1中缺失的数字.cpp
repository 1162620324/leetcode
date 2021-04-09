#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


//注意，题目的意思是n+1个数字填入n个元素的数组，必然有一个数填不进去，
//目标是找出这个数字，需要注意，这个数组是排序好的，并且元素不重复，因
//此意味着如果有一个数字不在数组内，那么之后的所有数字都将错位，所以
//就是找出第一个错位的元素即nums[i] != i;   
int missingNumber(vector<int> & nums){
    int len = nums.size();
    int i = 0, j = len - 1, m;
    while(i <= j){
        m = (i+j)/2;
        if(nums[m] == m) 
            i = m+1;
        else
            j = m-1;
    }
    return i;
}

int main(){

}