#include <bits/stdc++.h>
using namespace std;
const int MXV = 20005;
int par[MXV], r[MXV];
struct Edge
{
    int w;
    int x, y;
    Edge(){};
    Edge(int _w, int _x, int _y): w(_w), x(_x), y(_y){}
    bool operator<(const Edge&rhs)
    {
        return w < rhs.w;
    }
};

void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        par[i] = i;
        r[i] = 1;
    }
}

int Find(int x)
{
    return x == par[x] ? x : par[x] = Find(par[x]);
}

bool Union(int x, int y)
{
    // cout << x << ' ' << y << '\n';
    x = Find(x);
    y = Find(y);
    if(x == y)
    {
        return false;
    }
    if(r[x] == r[y])
    {
        par[y] = x;
        ++r[x];
    }
    else if(r[x] > r[y])
    {
        par[y] = x;
    }
    else
    {
        par[x] = y;
    }
    return true;
}

int main()
{
    int t, n, m;
    string s[105];
    vector<Edge> v;
    cin >> t;
    for(int ti = 1; ti <= t; ++ti)
    {
        cin >> n >> m;
        init(2 * n * m);
        for(int i = 0; i != n; ++i)
        {
            cin >> s[i];
        }
        for(int i = 1; i != n; ++i)for(int j = 0; j != m; ++j)
        {
            int no1 = 2 * ((i - 1) * m + j) + (s[i - 1][j] == '/');
            int no2 = 2 * ((i) * m + j) + (s[i][j] == '\\');
            Union(no1, no2);
        }
        v.clear();
        for(int i = 0, w; i != n; ++i)for(int j = 0; j != m; ++j)
        {
            cin >> w;
            v.push_back(Edge(w, 2 * (i * m + j), 2 * (i * m + j) + 1));
            if(j)
            {
                Union(2 * (i * m + j), 2 * (i * m + j) - 1);
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i != (int)v.size(); ++i)
        {
            if(Union(v[i].x, v[i].y))
            {
                ans += v[i].w;
            }
        }
        cout << "Case " << ti << ": " << ans << '\n';
    }
}