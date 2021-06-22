#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

vector<string> permutation(string s) 
{
    vector<string> res;
    vector<bool> st;
    string str;
    dfs(s, res, 0, str, st);
    return res;
}

void dfs(string s, vector<string>& res, int k, string & str, vector<bool> & st)
{
    if (k == s.size())
    {
        res.push_back(str);
        return;
    }
    
    for (int i = 0; i < s.size(); i++)
        if (!st[i])
        {
            string temp = str;
            str += s[i];
            st[i] = true;
            dfs(s, res, k + 1, str, st);
            st[i] = false;
            str = temp;
        }
}

int main()
{

}