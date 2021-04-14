#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


bool compare(int a, int b){
    string s1 = to_string(a), s2 = to_string(b);
    int i = 0;
    if((s1+s2) > (s2+s1)) return true;
    else return false;
}

string largestNumber(vector<int> & nums){
    sort(nums.begin(), nums.end(), compare);
    string res = "";
    for(int i = 0; i < nums.size(); i++){
        res += to_string(nums[i]);
    }
    return res;
}

string largestNumber(vector<int> & nums){
    sort(nums.begin(), nums.end(), [](const int &x, const int & y){
        long sx = 10, sy = 10;
        while (sx < x){
            sx *= 10;
        }
        while (sy < y){
            sy *= 10;
        }
        return sy * x + y > sx * y + x;
    });

    if(nums[0] = 0) return "0";

    string res = "";
    for(int num: nums){
        res += to_string(num);
    }
    return res;
}

int main(){
    vector<int> test = {111311, 1113};
    sort(test.begin(), test.end(), compare);
    for(int num: test){
        cout << num;
        cout << "ssss"; 
    }
}

