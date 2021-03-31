#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res(1);
    int n = nums.size();
    if(n == 0) return res;
    sort(nums.begin(), nums.end());

    int size = 1, last = nums[0];
    for(int i = 0; i < n; i++){
        if(last != nums[i]){
            last = nums[i];
            size = res.size();
        }
        int newSize = res.size();
        for(int j = newSize - size; j < newSize; j++){
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if(nums.empty()) return {};
    vector<vector<int>> res;
    vector<int> out;
    sort(nums.begin(), nums.end());
    helper(res, out, 0, nums);
    return res;
}

void helper(vector<vector<int>> &res, vector<int> & out, int pos, vector<int> nums){
    res.push_back(out);
    for(int i = pos; i < nums.size(); i++){
        out.push_back(nums[i]);
        helper(res, out, i+1, nums);
        out.pop_back();
        while(i+1 < nums.size() && S[i] == S[i+1]) i++;
    }
}



int main(){
    vector<int> n = {1,2,2};
    auto a = subsetsWithDup(n);
    cout << a.size();
}

