#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int MXN = 200005;
LL now_ans;

LL cal(LL n)
{
    if(n < 2)
    {
        return 0;
    }
    return n * (n - 1) / 2;
}

struct Edge
{
    int from, to, w;
    bool operator<(const Edge&rhs)const
    {
        return w < rhs.w;
    }
};

struct DisJointSet
{
    int p[MXN], sz[MXN];
    void init(int n)
    {
        for(int i = 0; i <= n; ++i)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int x)
    {
        if(x == p[x])
        {
            return x;
        }
        return p[x] = Find(p[x]);
    }
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if(x == y)
        {
            return;
        }
        now_ans -= cal((LL)sz[x]) + cal((LL)sz[y]);
        if(sz[x] < sz[y])
        {
            swap(x, y);
        }
        p[y] = x;
        sz[x] += sz[y];
        now_ans += cal((LL)sz[x]);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<LL> ans(m);
    vector<Edge> edges(n - 1);
    vector<PII> querys;
    DisJointSet djs;
    djs.init(n);
    for(int i = 0; i != n - 1; ++i)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
    }
    sort(edges.begin(), edges.end());
    for(int i = 0, x; i != m; ++i)
    {
        cin >> x;
        querys.push_back(make_pair(x, i));
    }
    sort(querys.begin(), querys.end());
    now_ans = 0;
    int i = 0;
    for(auto query: querys)
    {
        while(i < (int)edges.size() && edges[i].w <= query.first)
        {
            djs.Union(edges[i].from, edges[i].to);
            ++i;
        }
        ans[query.second] = now_ans;
    }
    for(int i = 0; i != m; ++i)
    {
        cout << ans[i] << " \n"[i == m - 1];
    }
}