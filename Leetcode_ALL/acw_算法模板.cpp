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

