#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

string reverseParentheses(string s)
{
    stack<char> stk;
    string res = "";
    int len = s.length();

    for (int i = 0; i < len; i ++)
    {
        if (s[i] != ')')
            stk.push(s[i]);
        else 
        {
            string temp = "";
            while (stk.top() != '(')
                temp += stk.top(), stk.pop();  
            stk.pop();
            for (char ch: temp) stk.push(ch);
        }
    }
    while (!stk.empty() && stk.top() != '(' ) res += stk.top(), stk.pop();
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

}