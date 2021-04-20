#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

vector<int> getNext(string p){
    vector<int> pi(p.size());
    for(int i = 1, j = 0; i < p.size(); i++){
        while(j > 0 && p[i] != p[j]){
            j = pi[j-1];
        }
        if(p[i]==p[j]){
            j++;
        }
        pi[i] = j;
    }

}

int strStr(string haystack, string needle){
    int n = haystack.size(), m = needle.size();
    if(m == 0) return 0;
    vector<int> pi = getNext(needle);
    for(int i = 0, j = 0; i < n; i ++){
        while(j > 0 && haystack[i] != needle[j]){
            j = pi[j-1];
        }
        if(haystack[i] == needle[j]){
            j++;
        }
        if(j == m){
            return i - m + 1;
        }
    }
    return -1;
}

int main(){

}