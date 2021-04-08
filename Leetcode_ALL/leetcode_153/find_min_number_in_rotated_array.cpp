#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int findMin(vector<int> & num){
    int left = 0, right = num.size()-1;
    int mid;
    while(left < right){
        mid = (left+right)/2;
        if(num[mid] < num[right])
            right = mid;
        else
            left = mid + 1;
    }
    return num[right];
}

int main(){
    vector<int> num = {5};
    cout << findMin(num);
}