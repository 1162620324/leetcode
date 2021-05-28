#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

vector<int> decode(vector<int>& encode){
    int n = encode.size() + 1;
    int total = 0;
    for(int i = 1; i <= n; i ++){
        total ^= i;
    }

    int odd = 0;
    for(int i = 0; i <= n; i += 2){
        odd ^= encode[i];
    }

    vector<int> perm(n);
    perm[0] = total ^ odd;
    for(int i = 0; i < n - 1; i ++){
        perm[i + 1] = perm[i] ^ encode[i];
    }
    return perm;
}

int main(){

}