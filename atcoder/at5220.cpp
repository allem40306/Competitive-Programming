/*
source: ABC 151 D Maze Master
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
const int MXV = 25;
string s[MXV];

int d[MXV][MXV];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int bfs(int h, int w, int a, int b)
{
    int mx = 0;
    queue<PII> q;
    q.push({a, b});
    memset(d, -1, sizeof(d));
    d[a][b] = 0;
    while(!q.empty())
    {
        PII k = q.front(); q.pop();
        for(int i = 0, x, y; i < 4; ++i)
        {
            x = k.first + dx[i];
            y = k.second + dy[i];
            if(x < 0 || x >= h || y < 0 || y >= w)
            {
                continue;
            }
            if(s[x][y] == '.' && d[x][y] == -1)
            {
                d[x][y] = d[k.first][k.second] + 1;
                mx = max(mx, d[x][y]);
                q.push({x, y});
            }
        }
    }
    return mx;
}

int main()
{
    IOS;
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; ++i)
    {
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if(s[i][j] == '#')
            {
                continue;
            }
            ans = max(ans, bfs(h, w, i, j));
        }
    }
    cout << ans << '\n';
}