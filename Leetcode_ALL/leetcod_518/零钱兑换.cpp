#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int change(int amount, vector<int>& coins) {
    int m = coins.size();
    vector<vector<int>> dp(m + 1, vector<int>(amount + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= m; i ++)
    {
        int coin = coins[i - 1];
        for (int j = 0; j <= amount; j ++)
        {
            dp[i][j] = dp[i - 1][j];
            int temp = j - coin;
            while(temp > 0)
            {
                dp[i][j] += dp[i - 1][temp];
                temp -= coin;
            }
        }
    } 
    return dp[m][amount];
}

int change_1(int amount, vector<int> & coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int coin: coins)
        for (int i = coin; i <= amount; i++)
            dp[i] += dp[i - coin];
    return dp[amount];
} 

int main()
{

}