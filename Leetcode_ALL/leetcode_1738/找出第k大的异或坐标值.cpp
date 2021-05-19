#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int partition(vector<int> &arr, int start, int end)
    {  
        srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。
	    int index = rand() % (end - start + 1) + start;
        swap(arr[start], arr[index]);
        int pivot = arr[start];//取哨兵元素
        int large = start;
        for (int i = start + 1; i <= end; i ++)
        {
            if (arr[i] > pivot)
            {
                ++ large;
                if (large != i)
                    swap(arr[large], arr[i]);
            }
        }
        swap(arr[large], arr[start]); //最后将哨兵元素交换至适当位置，并返回下标
        return large;
    }

    //利用快排找第k大的数
    void findKthLargest(vector<int> &arr, int k)
    {
        int start = 0, end = arr.size() - 1;
        int kth = partition(arr, start, end);
        while (k != kth + 1)
        {
            if (kth + 1 < k)
            {
                start = kth + 1;
                kth = partition(arr, start, end);
            }
            else
            {
                end = kth - 1;
                kth = partition(arr, start, end);
            }
        }
    }

    int kthLargestValue(vector<vector<int>>& matrix, int k) 
    {
        int m = matrix.size(),  n = matrix[0].size();
        vector<vector<int>> S(m + 1, vector<int>(n + 1, 0));
        vector<int> xorValue;

        //计算二维前缀和，存储结果
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
            {
                S[i + 1][j + 1] = S[i][j + 1] ^ S[i + 1][j] ^ S[i][j] ^ matrix[i][j];  
                xorValue.push_back(S[i + 1][j + 1]);
            }

        findKthLargest(xorValue, k);
        //nth_element(results.begin(), results.begin() + k - 1, results.end(), greater<int>());
        return xorValue[k - 1];
    }
};

int main()
{

}