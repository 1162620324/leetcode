#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//只要求得每个位置的左边到该位置的最大值，右边到该位置的最大值，两者取较小值然后减去当前位置的高度
//就能得到该位置能接的雨水的量
int trap_dp(vector<int>& height) {
    int len = height.size();
    vector<int> leftmax_position(len);
    vector<int> rightmax_position(len);

    leftmax_position[0] = height[0];
    rightmax_position[len-1] = height[len-1];

    int i = 0;
    while(i < len-1){
        leftmax_position[1+i] = max(leftmax_position[1+i-1], height[1+i]);
        rightmax_position[len-1-i-1] = max(rightmax_position[len-i-1], height[len-1-i-1]);
        i++;
    }

    int res = 0;
    for(int i = 0; i < len; i++){
        res += max(0, (min(leftmax_position[i], rightmax_position[i])-height[i]));
    }

    return res;
 }

 int trap_double_pointer(vector<int> & height){
    int len = height.size();
    if(len == 0) return 0;
    int left = 0, right = len - 1;
    int leftmax = height[0], rightmax = height[len-1];
    int res = 0;

    while(left < right){
        leftmax = max(leftmax, height[left]);
        rightmax = max(rightmax, height[right]);
        if(leftmax <= rightmax){ 
            res += (leftmax - height[left]);
            left++;
        }
        else{
            res += (rightmax - height[right]);
            right--;
        }
    }
    return res;
}
int trap_mono_stack(vector<int> & height){
    int res = 0;
    stack<int> stk;
    int n = height.size();
    for(int i = 0; i < n; i++){
        while(!stk.empty() && height[i] > height[stk.top()]){
            int top = stk.top();
            stk.pop();
            if(stk.empty()) break;
            int left = stk.top();
            int width = i-left-1;
            int water_height = min(height[i], height[left]) - height[top];
            res += width * water_height;
        }
        stk.push(i);
    }
    return res;
}

int main(){

}