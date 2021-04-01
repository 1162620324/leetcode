#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;


//10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
int clumsy(int N){
    int res = 0;
    bool flag = true;
    for(int i = 0; i < N; ++i){
        int temp = N-i;
        ++i;
        int k = 0;
        while(i < N && k < 2){
            switch (i%4)
            {
            case 1: 
                temp *= N-i;
                i++; k++;
                break;
            case 2:
                temp /= N-i;
                i++; k++;
                break;
            default:
                break;
            }
        }
        if(flag) {
            res = temp + N-i;
            flag = false;
        }
        else{
            res = res - temp + N-i;
        } 
    }
    return res;
}

int clumsy2(int N){
    stack<int> stk;
    stk.push(N);
    N--;

    int index = 0;
    while(N > 0){
        if(index % 4 == 0){
            stk.top() *= N;
        }
        else if(index % 4 == 1){
            stk.top() /= N;
        }
        else if(index % 4 == 2){
            stk.push(N);
        }
        else{
            stk.push(-N);
        }
        index++;
        N--;
    }
    int sum = 0;
    while(!stk.empty()){
        sum += stk.top(); 
        stk.pop();
    }
    return sum;
}

int main(){
    cout << clumsy(10);
}