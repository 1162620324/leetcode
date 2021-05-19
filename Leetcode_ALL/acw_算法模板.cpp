#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


int partition(int q[], int n, int start, int end){
    int small = start;
    int x = q[start];
    for(int i = start+1; i <= end; i++){
        if(q[i] < x){
            small ++;
            if(i != small){
                swap(q[small], q[i]);
            }
        }
    }
    swap(q[small], q[start]);
    return small;
}

//快速排序
void quick_sort(int q[], int l, int r){
    //递归终止条件
    if(l >= r) return;

    //取哨兵元素
    int x = q[l + r >> 1], i = l - 1, j = r + 1;

    //partition
    while(i < j){
        do i++ ; while(q[i] < x);
        do j++ ; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }

    //递归
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int N = 100010;
//归并排序
void merge_sort(int q[], int l, int r){
    //递归终止条件
    if(l >= r) return;

    //递归
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    //合并元素
    int tmp[N];
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];
    }
    while(i <= mid) tmp[k ++ ] = q[i ++ ];
    while(j <= r) tmp[k ++ ] = q[j ++ ];

    //倒腾数组
    for(i = l, j = 0; i < r; i ++, j++){
        q[i] = tmp[j];   
    }
}






//二分不意味着单调性，而是说数组一般区间满足某种性质，另一半不满足这种性质，二分可以把性质的边界找出来
//整数二分
bool check(int x){
    return false;
}

//|_______________||_______O_________________|
//满足性质的是右半区间，那么性质的边界就在左边，而且满足性质的边界可以取到，因此二分出来的是满足性质的端点r
int binary_search(int l, int r){
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;  
    }

    //返回lr都是可以的
    return l;
}


//|_______________O_______||_________________|
//满足性质的是左半区间，那么性质的边界就在右边边，而且满足性质的边界可以取到，因此二分出来的是满足性质的端点l
int binary_search(int l, int r){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}





//高精度加法
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> res;

    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i ++)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        res.push_back(t % 10);
        t /= 10;
    }

    if (t) res.push_back(t);
    return res;
}

//高精度减法
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> res;

    int t = 0;
    for (int i = 0; i < A.size(); i ++)
    {
        t = A[i] - t;
        if (i < B.size()) t = t - B[i];
        res.push_back((t + 10) % 10);
        if (t < 10) t = 1;
        else t = 0;
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

//高精度乘法
vector<int> multi(vector<int> &A, int b)
{
    vector<int> res;
    
    int t = 0;
    for (int i = 0; i < A.size() || t != 0; i ++)
    {
        if (i < A.size()) t = A[i] * b + t;
        res.push_back((t % 10));
        t /= 10;
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

//高精度除法
vector<int> div(vector<int> &A, int b)
{
    vector<int> res;
    int r = 0;

    for (int i = A.size() - 1; i >= 0; i ++) 
    {
        r = r * 10 + A[i];
        res.push_back(r / b);
        r %= b;
    }

    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() != 0) res.pop_back();

    return res;
}






//一维前缀和:S[i] = a[1] + a[2] + a[3] +... + a[i]
//       S[i] = S[i - 1] + a[i]
//       a[l] + ... + a[r] = S[r] - S[l - 1]

//二维前缀和： 以 (x1, y1) 为左上角,(x2, y2) 为右下角的子矩阵的和：
//        S[x2, y2] - S[x2, y1 - 1] - S[x1 - 1, y2] + S[x1 - 1, y1 - 1]

//位运算：
//求第k位数字：n >> k & 1;
//返回n的二进制最后一个1：n & (~n)


            