#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int guessNumber(int n) 
{
    int l = 1, r = n;
    while(l < r)
    {
        int mid = l + ((r-l) >> 1);
        if (guess(mid) == 0) return mid;
        else if (guess(mid) == -1) r = mid;
        else l = mid + 1;
    } 
    return -1;
}

int main()
{

}