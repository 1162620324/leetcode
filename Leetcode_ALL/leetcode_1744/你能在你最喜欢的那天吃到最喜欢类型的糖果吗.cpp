#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    vector<bool> res;
    int n = candiesCount.size();
    vector<long long> sum(n);
    sum[0] = candiesCount[0];

    for (int i = 1; i < n; i ++)
        sum[i] = sum[i - 1] + candiesCount[i];  

    for (const auto & q: queries)
    {
        int fav_tp = q[0], fav_day = q[1], daily_cap = q[2];

        long long x1 = fav_day + 1;
        long long y1 = (long long)(fav_day + 1) * daily_cap;
        long long x2 = (fav_tp == 0 ? 1 : sum[fav_tp - 1] + 1);
        long long y2 = sum[fav_tp];

        res.push_back(!(x1 > y2 || y1 < x2));
    }
    return res;
}

int main()
{

}