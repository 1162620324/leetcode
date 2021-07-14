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
    //sigma(|nums1[i] - nums2[i]|) - max;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 + 7;
        int n = nums1.size();
        int sigma = 0;
        vector<pair<int, int>> abs_minus;

        for (int i = 0; i < n; i ++)
        {
            int minus = abs(nums1[i] - nums2[i]);
            abs_minus.push_back({minus, i});
            sigma += minus;
            sigma %= mod;
        }

        sort(abs_minus.begin(), abs_minus.end(), greater<PII>());
        sort(nums1.begin(), nums1.end());

        int maxn = 0;
        for (auto & p: abs_minus)
        {
            int minus = p.first, index = p.second;
            int i = lower_bound(nums1.begin(), nums1.end(), nums2[index]) - nums1.begin();
            if (i > 0)
                maxn = max(maxn, minus - (nums2[index] - nums1[i - 1]));
            if (i < n)
                maxn = max(maxn, minus - (nums1[i] - nums2[index]));
        }  
        return (sigma - maxn + mod) % mod;
    }
};

int main()
{

}