#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;





int main(){
    int n;
    cin >> n;
    vector<vector<int>> num(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            cin >> num[i][j];
        }
    }


}



//dp[i][j]表示s(0~i-1)和s(0~j-1)最长的公共子序列
//状态转移方程：
//dp[i][j] = max(dp[i-1][j],dp[i][j-1], dp[i-1][j-1]+1])   if s[i-1] == s[j-1]
//dp[i][j] = max(dp[i-1][j],dp[i][j-1], dp[i-1][j-1])   if s[i-1] != s[j-1]
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= n; i++)
        dp[0][i] = 0;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int temp = max(dp[i-1][j], dp[i][j-1]);//先求出当前text[i]和text[j]不相等时的最长公共子序列
            if(text1[i-1] == text2[j-1])
                dp[i][j] = max(temp, dp[i-1][j-1]+1);
            else
                dp[i][j] = max(temp, dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}


