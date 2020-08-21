#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e3 + 5;
const int MXV = 1e3 + 5;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);
struct Edge
{
    int t, w;
};
int n, m;
int timeCnt, bccCnt;
int mn, cnt;
vector<Edge> G[MXV];
vector<int> dep(MXV), low(MXV);

void init(int n)
{
    mn = INF;
    cnt = timeCnt = bccCnt = 0;
    fill(dep.begin(), dep.end(), 0);
    fill(low.begin(), low.end(), 0);
    FOR(i, 1, n + 1) { G[i].clear(); }
}

void dfs(int u, int f)
{
    dep[u] = low[u] = ++timeCnt;
    bool flag = false;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i].t;
        if (v == f && !flag)
        {
            flag = true;
            continue;
        }
        if (dep[v] == 0)
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dep[u])
            {
                mn = min(mn, G[u][i].w);
            }
        }
        else
        {
            low[u] = min(low[u], dep[v]);
        }
    }
}

void tarjan(int n)
{
    FOR(i, 1, n + 1)
    {
        if (dep[i] == 0)
        {
            dfs(i, -1);
            ++cnt;
        }
    }
}

int main()
{
    while (scanf("%d %d", &n, &m), n || m)
    {
        init(n);
        for (int i = 0, x, y, w; i != m; ++i)
        {
            scanf("%d %d %d", &x, &y, &w);
            G[x].push_back({y, w});
            G[y].push_back({x, w});
        }
        tarjan(n);
        if (cnt >= 2)
        {
            printf("0\n");
        }
        else if (mn == INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", max(1, mn));
        }
    }
}
