#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

int counts = 0;

    void dfs(vector<int> &nums, int u, int sum, int target)
    {
        if (u == nums.size())
        {
            if(sum == target)
                counts ++;
            return;
        }
        dfs(nums, u + 1, sum + nums[u], target);
        dfs(nums, u + 1, sum - nums[u], target);
    }

unordered_map<string, int> cache;

int dfs1(vector<int> & nums, int target, int u, int cur)
{
    string key = to_string(u) + '_' + to_string(cur);
    if(cache.count(key)) return cache[key];
    if (u == nums.size())
    {
        cache[key] = (cur == target ? 1 : 0);
        return cache[key];
    }
    int left = dfs1(nums, target, u + 1, cur + nums[u]);
    int right = dfs1(nums, target, u + 1, cur - nums[u]);
    cache[key] = left + right;
    return cache[key];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int num : nums)
        sum += num;
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0)
        return 0;
    int n = nums.size(), neg = diff / 2;
    vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        int num = num[i - 1];
        for (int j = 0; j <= neg; j ++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= num) 
                dp[i][j] += dp[i - 1][j - num];
        }
    }
    return dp[n][neg];

}



int main()
{

}