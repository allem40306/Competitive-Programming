#include <bits/stdc++.h>
using namespace std;
const int MXV = 1005;
int sccCnt;
int sccSz[MXV], sccNo[MXV];
vector<int> G[MXV], TG[MXV], leave, sccG[MXV];
bitset<MXV> visit, isRoot;

void init(int n, int m)
{
    sccCnt = 0;
    memset(sccSz, 0, sizeof(sccSz));
    memset(sccNo, 0, sizeof(sccNo));
    for(int i = 1; i <= n; ++i)
    {
        G[i].clear();
        TG[i].clear();
        sccG[i].clear();
    }
    leave.clear();
    visit.reset();
    isRoot.set();
    for(int i = 0, x, y; i != m; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
        TG[y].push_back(x);
    }
}

void dfsForStamp(int u)
{
    visit[u] = true;
    for(auto v: G[u])
    {
        if(!visit[v])
        {
            dfsForStamp(v);
        }
    }
    leave.push_back(u);
}

void dfsForScc(int u, int cnt)
{
    visit[u] = true;
    ++sccSz[cnt];
    sccNo[u] = cnt;
    for(auto v: TG[u])
    {
        if(!visit[v])
        {
            dfsForScc(v, cnt);
        }
    }
}

void kosaraju(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        if(!visit[i])
        {
            dfsForStamp(i);
        }
    }
    visit.reset();
    for(int i = leave.size() - 1; i >= 0; --i)
    {
        int u = leave[i];
        if(!visit[u])
        {
            ++sccCnt;
            dfsForScc(u, sccCnt);
        }
    }
}

int sol(int n, int m)
{
    if(!n)
    {
        return 0;
    }
    if(!m)
    {
        return 1;
    }
    for(int u = 1; u <= n; ++u)for(auto v: TG[u])
    {
        if(sccNo[u] == sccNo[v])
        {
            continue;
        }
        sccG[sccNo[u]].push_back(sccNo[v]);
        isRoot[sccNo[v]] = false;
    }

    int ans = 0;
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; ++i)
    {
        if(isRoot[i])
        {
            q.push({i, sccSz[i]});
        }
    }
    while(!q.empty())
    {
        auto k = q.front(); q.pop();
        ans = max(ans, k.second);
        for(auto it: sccG[k.first])
        {
            q.push({it, k.second + sccSz[it]});
        }
    }
    return ans;
}

int main()
{
    int t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        init(n, m);
        kosaraju(n);
        cout << sol(n, m) << '\n';
    }
}