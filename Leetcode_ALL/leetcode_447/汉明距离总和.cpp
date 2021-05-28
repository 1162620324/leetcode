#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;



int totalHanmmingDistance(vector<int> &nums)
{
    int res = 0;
    int len = nums.size();

    for (unsigned int i = 0x1; i ; i << 1)
    {
        int ones = 0;
        for (int j = 0; j < len; j ++)
            if ((nums[j] & i) != 0) ones ++;
        res += (len - ones) * ones;
    }
    
    return res;
}

int main()
{

}