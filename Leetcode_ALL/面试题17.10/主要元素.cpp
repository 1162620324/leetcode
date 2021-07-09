#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int majorityElement(vector<int> & nums)
{
    int count = 0, candidate = 0;
    for (auto & num: nums)
    {
        if (count == 0)
        {
            candidate = num;
            count ++;
        }
        else 
        {
            if (num == candidate)
                count ++;
            else 
                count --;
        }
    }
    int count = 0;
    for (auto & num: nums)
        if (num == candidate)
            count ++;
            
    return count * 2 > nums.size() ? candidate : -1;
}

int main()
{

}