#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:

    typedef pair<int, int> PII;

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<PII> point;
        vector<vector<int>> res;

        for (int i = 0; i < n; i ++)
        {
            int l = buildings[i][0], r = buildings[i][1], h = buildings[i][2];
            point.push_back({l, -h});
            point.push_back({r, h});
        }

        sort(point.begin(), point.end());

        multiset<int> mset({0});
        int pre_height = 0;

        for (auto & p : point)
        {
            int x = p.first, y = p.second;
            if (y < 0)
                mset.insert(-y);
            else
                mset.erase(mset.find(y));
            
            auto maxHeight = *mset.rbegin();
            if (maxHeight != pre_height)
            {
                res.push_back({x, maxHeight});
                pre_height = maxHeight;
            }

        }
        return res;
    }
};