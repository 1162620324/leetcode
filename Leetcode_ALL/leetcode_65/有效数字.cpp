#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

//本题需要识别一个使用科学计数法表示的数字。AeB,A可以时小数或整数， B必须是整数
//其中e和B可以不存在，分为两部分判断，首先是否有e，如果没有那么就必须是整数，如果有
//那么前半部分A可以时整数或小数，后半部分B必须是整数。

bool check(string str, int start, int end, bool mustInt)
{
    if (start > end) return false;
    if (str[start] == '+' || str[end] == '-') start ++;
    bool hasDot = false, hasNum = false;
    for (int i = start; i <= end; i++)
    {
        if (str[i] == '.') 
        {
            if (mustInt || hasDot) return false;
            hasDot = true;
        }
        else if (str[i] >= '0' && str[i] <= '9')
            hasNum = true;
        else return false;
    }
    return hasNum;
}

bool isNumber(string s) 
{
    int n = s.size();
    int idx = -1;
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == 'e' || s[i] == 'E')
        {
            if (idx == -1) idx = i;
            else return false;
        }
    }

    bool ans = true;
    if (idx != -1)
    {
        ans &= check(s, 0, idx - 1, false);
        ans &= check(s, idx + 1, n - 1, true);
    }
    else 
        ans &= check(s, 0, n - 1, false);

    return ans;
}

int main()
{

}