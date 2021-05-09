#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool canMake(vector<int> & bloomDay, int days, int m, int k){
    int boquets = 0;
    int flowers = 0;
    for(int i = 0; i < bloomDay.size() && boquets < m; i ++){
        if(bloomDay[i] <= days){
            flowers ++;
            if(flowers == k){
                boquets ++;
                flowers = 0;
            }
        }
        else{
            flowers = 0;
        }
    }
    return boquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k){
    if(k * m > bloomDay.size()) return -1;

    int l = 1, r = 1;
    for(auto day: bloomDay){
        r = max(r, day);
    }

    while(l < r){
        int mid = l + r >> 1;
        if(canMake(bloomDay, mid, m, k)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){

}