#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <string.h>
#include <numeric>

using namespace std;

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)    
{
    int m = group.size();
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= m; i ++)
    {
        int members = group[i - 1], earn = profit[i - 1];
        for (int j = 0; j <= n; j ++ )
        {
            for (int k = 0; k <= minProfit; k ++)
            {
                if (j < members)
                    dp[i][j][k] = dp[i - 1][j][k];
                else
                    dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % ((int)1e9 + 7);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i <= n; i ++)
        sum = (sum + dp[m][i][minProfit]) % ((int)1e9 + 7);
    return sum;
}

int main()
{

}