#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int numWays(int steps, int arrLen){
    int M = 1e9 + 7;
    int n = min(arrLen - 1, steps);
    vector<vector<int>> dp(steps + 1, vector<int>(n + 1));
    dp[0][0] = 1;

    for(int i = 1; i <= steps; i ++){
        for(int j = 0; j <= n; j ++){
            dp[i][j] = dp[i - 1][j];
            if(j - 1 >= 0){
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= M;
            }
            else if(j + 1 <= n){
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= M;
            }
        }
    }
    return dp[steps][0];
}

int main(){

}