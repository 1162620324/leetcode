#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

//区间dp
bool isScramble(string s1, string s2){
    int len1 = s1.size(), len2 = s2.size();
    if(len1 != len2) return false;

    vector<vector<vector<bool> > > dp(len1, vector<vector<bool>>(len2, vector<bool>(len1+1)));

    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            dp[i][j][1] = (s1[i] == s2[j]);
        }
    }

    //枚举长度
    for(int len = 2; len <= len1; len++){
        //枚举s1的起点
        for(int i = 0; i <= len1 - len; i++){
            //枚举s2的起点
            for(int j = 0; j <= len2 - len; j++){
                //枚举长度为len的分割点
                for(int k = 1; k <= len-1; k++){
                    if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                    }

                    if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                    }
                }
            }
        }
    }
    return dp[0][0][len1];
}

//记忆化深搜
class Solution{
public:
    vector<vector<vector<int>>> cache;
    string s1, s2;
    int n ;
    int NO = -1, YES = 1, EMPTY = 0;

    bool isScramble(string _s1, string _s2){
        s1 = _s1;
        s2 = _s2;
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;

        n = s1.size();
        cache.resize(n, vector<vector<int>>(n, vector<int>(n+1, 0)));

        return dfs(0, 0, n);
    }

    bool dfs(int i, int j, int len){
        if(cache[i][j][len]!=EMPTY)
            return cache[i][j][len] == YES;
        
        string a = s1.substr(i, len), b = s2.substr(j, len);

        if(a == b)
            return cache[i][j][len] = YES || true;
        
        if(!check(a, b))
            return cache[i][j][len] = NO && false;

        for(int k = 1; k <= len-1; k++){
            if(dfs(i, j, k) && dfs(i+k, j+k, len-k)){
                return cache[i][j][len] = YES || true;  
            }
            if(dfs(i, j+len-k, k) && dfs(i+k, j, len-k)){
                return cache[i][j][len] = YES || true;
            }
        }
        cache[i][j][len] = false;
        return false;
    }

    bool check(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        vector<int> cnt1(26,0), cnt2(26, 0);
        for(auto c: cnt1){
            cnt1[c-'a']++;
        }
        for(auto c: cnt2){
            cnt2[c-'a']++;
        }
        return cnt1 == cnt2;
    }

};

int main(){
    int a = 0;
    bool b = (-1) && true;
    cout << b;
    if((-1) ){
        cout << "ssss";
    }
}
