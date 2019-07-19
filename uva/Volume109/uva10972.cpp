#include <bits/stdc++.h>
using namespace std;
const int MXV = 1005;
vector<int> G[MXV];

// BCC
int timeCnt, bccCnt;
int dep[MXV], low[MXV], bccno[MXV];
int deg[MXV];
vector<int> bcc[MXV];
using PII = pair<int, int>;
vector<PII> bridge;
set<PII> bridgeSet;

void init(int n, int m)
{
    for(int i = 0; i <= n; ++i)
    {
        G[i].clear();
    }
    for(int i = 0, x, y; i < m; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    // BCC
    timeCnt = bccCnt = 0;
    memset(dep, -1, sizeof(dep));
    memset(deg, 0, sizeof(deg));
    memset(low, -1, sizeof(low));
    memset(bccno, -1, sizeof(bccno));
    bridge.clear();
    bridgeSet.clear();
}

void tarjan(int u, int f)
{
    dep[u] = low[u] = ++timeCnt;
    for(auto v: G[u])
    {
        if(v == f)
        {
            continue;
        }
        if(dep[v] == -1)
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dep[u] < low[v])
            {
                bridge.push_back({u, v});
                bridgeSet.insert({u, v});
                bridgeSet.insert({v, u});
            }
        }
        else if(low[u] > dep[v])
        {
            low[u] = dep[v];
        }
    }
}

void floodFill(int u)
{
    queue<int> q;
    ++bccCnt;
    q.push(u);
    while(!q.empty())
    {
        u = q.front(); q.pop();
        bccno[u] = bccCnt;
        bcc[bccCnt].push_back(u);
        for(auto v: G[u])
        {
            if(bccno[v] == -1 && !bridgeSet.count({u, v}))
            {
                q.push(v);
            }
        }
    }
}

int solve(int n, int m)
{
    for(int i = 1; i <= n; ++i)
    {
        if(dep[i] == -1)
        {
            tarjan(i, -1);
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        if(bccno[i] == -1)
        {
            floodFill(i);
        }
    }

    if(bccCnt == 1)
    {
        return 0;
    }
    for(auto it: bridge)
    {
        int u = it.first, v = it.second;
        ++deg[bccno[u]];
        ++deg[bccno[v]];
    }
    int deg0Cnt = 0, deg1Cnt = 0;
    for(int i = 1; i <= bccCnt; ++i)
    {
        if(deg[i] == 0)
        {
            ++deg0Cnt;
        }
        else if(deg[i] == 1)
        {
            ++deg1Cnt;
        }
    }
    return deg0Cnt + (deg1Cnt + 1) / 2;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        init(n ,m);
        cout << solve(n, m) << '\n';
    }
}