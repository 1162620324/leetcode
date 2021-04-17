#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>
using std::unordered_map;

using namespace std;

int containNearByAlmostDupicate(vector<int> & nums, int k, int t){
    int n = nums.size();
    set<int> rec;
    for(int i = 0; i < n; i++){
        auto iter = rec.lower_bound(max(nums[i], INT32_MIN+t)-t);
        if(iter != rec.end() && *iter <= (min(nums[i], INT32_MAX-t)+t)){
            return true;
        }
        rec.insert(nums[i]);
        if(i >= k)
            rec.erase(nums[i-k]);
    }
    return false;
}

int getID(int x, long w){
    return  x < 0 ? (x+1ll)/w-1 : x / w;
}

int bucket(vector<int>& nums, int k, int t){
    unordered_map<int , int> mp;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        long x = nums[i];
        int id = getID(x, t+1ll);
        if(mp.count(id)){
            return true;
        }

        if(mp.count(id-1) && abs(x-mp[id-1]) <= t){
            return true;
        }
        if(mp.count(id+1) && abs(x-mp[id+1] <= t)){
            return true;
        }
        mp[id] = x;
        if(i >= k){
            mp.erase(getID(nums[i-k], t+1ll));
        }
    }
    return false;
}

int main(){

}