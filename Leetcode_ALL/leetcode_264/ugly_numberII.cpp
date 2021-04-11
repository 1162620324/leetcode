#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int nthUglyNumber(int n){
    vector<int> dp(n);
    dp[0] = 1;
    int pM2 = 0, pM3 = 0, pM5 = 0;


    for(int i = 1; i < n; i++){
        int tmp2 = dp[pM2]*2, tmp3 = dp[pM3]*3, tmp5 = dp[pM5]*5;
        int mintmp = min(min(tmp2, tmp3), tmp5);
        dp[i] = mintmp;
        if(mintmp == tmp2) pM2++;
        if(mintmp == tmp3) pM3++;
        if(mintmp == tmp5) pM5++;
    }

    return dp[n-1];

}

int main(){

}