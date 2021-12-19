#include <bits/stdc++.h>
using namespace std;
const int MXN = 105;
int n;
int a[MXN][MXN];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy)
{
    int ans = 1; a[sx][sy] = 1;
    while(!q.empty())
    {
        q.pop();
    }
    q.push({sx, sy});
    while(!q.empty())
    {
        auto k = q.front(); q.pop();
        // cout << k.first << ' ' << k.second << '\n';
        for(int i = 0; i != 4; ++i)
        {
            int x = k.first + dx[i];
            int y = k.second + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 1)
            {
                continue;
            }
            ++ans;
            a[x][y] = 1;
            q.push({x, y});
        }
    }
    return ans;
}

int main()
{
    int t, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        memset(a, 0, sizeof(a));
        for(int i = 0, x, y; i < k; ++i)
        {
            cin >> x >> y;
            --x; --y;
            a[x][y] = 1;
        }
        int sx, sy;
        cin >> sx >> sy;
        --sx; --sy;
        cout << bfs(sx, sy) << '\n'; 
    }
}