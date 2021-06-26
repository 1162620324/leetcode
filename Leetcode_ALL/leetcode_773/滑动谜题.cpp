#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int bfs(string start, string end)
{
    unordered_map<string, int> dist;
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty())
    {
        string t = q.front(); q.pop();
        int d = dist[t];
        if (t == end) return d;
        
        int pos = t.find('0');//4
        int x = pos / 3, y = pos % 3;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a <= 1 && b >= 0 && b <= 2)
            {
                int ex_pos = a * 3 + b;
                swap (t[pos], t[ex_pos]);
                if (dist.find(t) == dist.end())
                {  
                    q.push(t);
                    dist[t] = d + 1;
                }
                swap (t[pos], t[ex_pos]);
            }
        }
    }
    return -1;
}

int slidingPuzzle(vector<vector<int>>& board) 
{
    string start = "";
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 3; j ++)
            start += to_string(board[i][j]);
    return bfs(start, "123450");

}
};

int main()
{
    
}