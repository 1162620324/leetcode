#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

const int N = 510;
int dp[N][N];

bool stoneGame(vector<int> & piles)
{
    
    int len = piles.size();
    for (int i = 0; i < len; i ++)
        dp[i][i] = piles[i];

    for (int i = 1; i < len; i ++)
        for (int j = 0; j <= len - i; j ++)
            dp[j][j + len] = max(piles[j] - dp[j + 1][j + len], piles[j + len] - dp[j][j + len - 1]);
    
    return dp[0][len - 1] > 0;
        
}

int main()
{

}