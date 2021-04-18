#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int removeDuplicates(vector<int> & nums){
    int n = nums.size();
    if(n == 0 || n == 1){
        return n;
    }

    for(auto iter = nums.begin()+1; iter != nums.end(); ){
        if(*iter == *(iter-1)){
            iter = nums.erase(iter);
        }
        else{
            iter++;
        }
    }
    return nums.size();
}

//better:双指针
int removeDuplicates_better(vector<int> &nums){
    int n = nums.size();
    if(n == 0)
        return n;
    
    int fast = 1, slow = 1;
    while(fast < n){
        if(nums[fast] != nums[fast-1]){
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}

int main(){
    vector<int> s = {1,1,1,2,3,4,4};
    cout << removeDuplicates(s);
}