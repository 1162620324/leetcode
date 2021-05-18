#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int countTriplets(vector<int>& arr) {
    int res = 0;
    vector<int> S(arr.size()+1, 0);
    for (int i = 0; i < arr.size(); i++)
        S[i + 1] = S[i] ^ arr[i];
    
    for (int i = 0; i < arr.size(); i ++)
    {
        for (int k = i + 1;k < arr.size(); k ++)
        {
            if(S[i] == S[k + 1]) res += k - i;
        }
    }
    return res;
}

int main()
{

}