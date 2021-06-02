#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2) return false;

    unordered_map<int, int> mp;
    mp[0] = -1; 
    int remainder = 0;  

    for (int i = 0; i < n; i ++)
    {
        remainder = (remainder + nums[i]) % k;
        if(mp.count(remainder)) {if (i - mp[remainder] >= 2) return true;}
        else
            mp[remainder] = i;
    }
    return false;

}

int main()
{

}