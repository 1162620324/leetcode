#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int hammingDistance(int x, int y)
{
    int res = 0;
    for (unsigned int z = 0x1; z; z <<= 1)
        if ((x & z) != (y & z)) res ++;
    return res;
}

int lowbit(int x)
{
    return x & (-x);
}

int hammingWeight(int x)
{
    int count = 0;
    while (x)
    {
        x = x - lowbit(x);
        count ++;
    }
    return count;
}

int hammingDistance(int x, int y)
{
    return hammingWeight(x ^ y);
}

int main()
{

}