#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> S(m + 1, vector<int>(n + 1, 0));
    int res = 0;

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            S[i][j] = S[i - 1][j] + S[i][j - 1] + matrix[i - 1][j - 1] - S[i - 1][j - 1];
    
    for (int top = 0; top < m; top ++)
        for (int bot = top; bot < m; bot ++)
        {
            int cur = 0;
            unordered_map<int, int> umap;
            for (int r = 0; r < n; r ++)
            {
                cur = S[bot + 1][r + 1] - S[top][r + 1];
                if (cur == target) res ++;
                if (umap.find(cur - target) != umap.end()) res += umap[cur - target];
                if (umap.find(cur) != umap.end()) umap.insert({cur, umap[cur] + 1});
                else umap.insert({cur, 1});
            }  
        }  

    return res;
}

int main()
{

}