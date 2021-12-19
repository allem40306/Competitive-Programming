#include <bits/stdc++.h>
using namespace std;
const int MXN = 105;
int m, n;
int a[MXN][MXN];
queue<pair<int, int>> q;
vector<int> v;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int sx, int sy)
{
    int tot = a[sx][sy]; a[sx][sy] = 0;
    while(!q.empty())
    {
        q.pop();
    }
    q.push({sx, sy});
    while(!q.empty())
    {
        auto k = q.front(); q.pop();
        for(int i = 0; i != 4; ++i)
        {
            int x = k.first + dx[i];
            int y = k.second + dy[i];
            if(x < 0 || x > m || y < 0 || y > n || a[x][y] == 0)
            {
                continue;
            }
            tot += a[x][y];
            a[x][y] = 0;
            q.push({x, y});
        }
    }
    v.push_back(tot);
    return;
}

int main()
{
    while(cin >> n >> m)
    {
        v.clear();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(a[i][j])
                {
                    bfs(i, j);
                }
            }
        }
        sort(v.begin(), v.end());
        cout << v.size() << '\n' << v[v.size() - 1] << '\n'; 
    }
}