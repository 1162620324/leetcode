#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool isUgly(int n){
    if(n <= 0) return false;
    vector<int> factor = {2,3,5};
    for(int fac : factor){
        while (n % fac == 0)
        {
            n /= fac;
        }
        
    }
    return n == 1;
}

int main(){

}