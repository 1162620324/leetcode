#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int nuDecodings(string s){
    int n = s.size();
    vector<int> f(n+1);
    f[0] = 1;
    for(int i = 0; i <= n; i++){
        if(s[i] != '0'){
            f[i] += f[i - 1];
        }
        if(i > 1 && s[i - 1] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26 )){
            f[i] += f[i-2];
        }
    }
    return f[n];
}

int main(){

}