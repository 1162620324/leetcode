#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

//一个数是2的幂，那么该数的2进制表示只有一个1，所以只需要判断是否只含一个1就可以
// n & (n - 1) 去掉最后一个1
// n & (- n) 取出最后一个1

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}


int main()
{

}