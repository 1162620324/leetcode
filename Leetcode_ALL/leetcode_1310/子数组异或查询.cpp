#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

vector<int> XorQueries(vector<int> & arr, vector<vector<int>>& queries){
    int n = arr.size();
    vector<int> sum(n + 1);
    sum[0] = 0;
    for(int i = 1; i <= n; i ++ ){
        sum[i] = sum[i - 1] ^ arr[i - 1];
    }

    vector<int> res(queries.size());
    for(auto item: queries){
        res.push_back(sum[item[1] + 1] ^ sum[item[0]]);
    }

    return res;
}

int main(){

}