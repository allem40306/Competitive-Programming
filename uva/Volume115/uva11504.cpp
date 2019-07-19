#include <bits/stdc++.h>
using namespace std;
const int MXV = 100005;
int sccCnt, sccNo[MXV];
vector<int> G[MXV], TG[MXV], leave;
bitset<MXV> visit, isRoot;

void init(int n, int m)
{
    sccCnt = 0;
    memset(sccNo, 0, sizeof(sccNo));
    for(int i = 1; i <= n; ++i)
    {
        G[i].clear();
        TG[i].clear();
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
    for(auto v: TG[u])
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
    sccNo[u] = cnt;
    for(auto v: G[u])
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
    for(int i = leave.size() - 1, u; i >= 0; --i)
    {
        u = leave[i];
        if(!visit[u])
        {
            ++sccCnt;
            dfsForScc(u, sccCnt);
        }
    }
}

int sol(int n)
{
    for(int u = 1; u <= n; ++u)for(auto v: G[u])
    {
        if(sccNo[u] == sccNo[v])
        {
            continue;
        }
        isRoot[sccNo[v]] = false;
    }
    int ans = 0;
    for(int i = 1; i <= sccCnt; ++i)
    {
        if(isRoot[i])
        {
            ++ans;
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
        cout << sol(n) << '\n';
    }
}