#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;
const int N = 610;

vector<int> getZerosOnes(string str)
{
    vector<int> zeroOnes(2);
    int len = str.size();
    for (int i = 0; i < len; i ++)
        zeroOnes[str[i] - '0'] ++;
    return zeroOnes; 
}



int findMaxForm(vector<string>& strs, int m, int n)
{
    int dp[N][m + 1][n + 1];
    memset(dp, 0, sizeof dp);
    int len = strs.size();
    for (int i = 1; i <= len; i ++)
    {
        vector<int> zeroOnes = getZerosOnes(strs[i - 1]);
        int zeros = zeroOnes[0], ones = zeroOnes[1];
        for (int j = 0; j <= m; j ++ )
            for (int k = 0; k <= n; k ++)
            {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= zeros && k >= ones)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
            }
    }
    return dp[len][m][n];
}

int main()
{

}