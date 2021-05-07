#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
 
int xorOperation(int n, int start){
    int res = 0;
    for(int i = 0; i < n; i ++){
        res = res ^ (start + 2 * i);
    }
    return res;
}

//异或操作的规律
//x ^ x=0；
//x ^ y = y ^ x （交换律）；
//(x ^ y) ^ z = x ^ (y ^ z)（结合律）；
//x ^ y ^ y = x（自反性）；
//∀i∈Z，有 4i ^ (4i+1) ^ (4i+2) ^ (4i+3) = 0 


int sumXor(int x){
    if(x % 4 == 0){
        return x;
    }
    if(x % 4 == 1){
        return 1;
    }
    if(x % 4 == 2){
        return x + 1;
    }
    return 0;
}

int xorOpertion_1(int n, int start){
    int s = start >> 1, e = n & start & 1;
    int ret = (sumXor(s - 1) ^ sumXor(s + n - 1));
    return ret << 1 | e;
}

int main(){

}