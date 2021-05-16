#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

const int N = 200010;
int son[N][2], idx = 0;

void insert(int x)
{
    int p = 0;
    for (int i = 30; ~i; i --)
    {
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u]; 
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; ~i; i --)
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            res += 1 << i;
            p = son[p][!u];
        }
        else p = son[p][u];
    }
    return res;
}

int findMaximumXor(vector<int> & nums)
{
    int res = 0;
    for (auto num: nums) insert(num);
    for (auto num: nums) res = max(res, query(num));

    return res;
}

int main()
{
    vector<int> nums {3,10,5,25,2,8};
    cout << findMaximumXor(nums);
    return 0;
}