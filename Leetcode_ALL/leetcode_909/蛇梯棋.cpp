#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

pair<int, int> id2rc(int id, int n) 
{
    int r = (id - 1) / n, c = (id - 1) % n;
    if (r % 2 == 1) 
        c = n - 1 - c;
            
    return {n - 1 - r, c};
}


int snakesAndLadders(vector<vector<int>>& board) 
{
    
}

int main()
{
    
}