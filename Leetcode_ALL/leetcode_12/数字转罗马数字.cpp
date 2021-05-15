#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

string intToRoman(int num)
{
    string res = "";
    vector<char> roman {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    vector<int> value {1000, 500, 100, 50, 10, 5, 1};

    for (int i = 0; i < 7; i += 2)
    {
        int x = num / value[i];
        if (x < 4)
        {
            for (int j = 0; j < x; j ++ ) res += roman[i];
        }
        else if (x == 4)
        {
            res = res + roman[i] + roman[i - 1];
        }
        else if (x > 4 && x < 9)
        {
            res += roman[i - 1];
            for (int j = 6; j < x; j ++ ) res += roman[i];
        }
        else if (x == 9)
        {
            res = res + roman[i] + roman[i - 2];
        }

        num %= value[i];
    }
    return res;
}

