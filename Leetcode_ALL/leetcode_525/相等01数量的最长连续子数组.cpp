#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int counter = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i ++)
    {
        int num = nums[i];
        if(num == 1) counter ++;
        else counter --;
        if (mp.count(counter))
            res = max(res, i - mp[counter]);
        else    
            mp[counter] = i;
    }
    return res;
}

int main()
{

}