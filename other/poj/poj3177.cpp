#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>


using namespace std;
const int INF = 1e9;
const int MXN = 5e3 + 5;
const int MXV = 5e3 + 5;
typedef pair<int, int> PII;
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

int timeCnt, bccCnt;
int dep[MXV], low[MXV], bccno[MXV];
int deg[MXV];
vector<int> G[MXV];
vector<int> bcc[MXV];
vector<PII> bridge;
set<PII> bridgeSet;

void init(int n, int m)
{
    for (int i = 0; i <= n; ++i)
    {
        G[i].clear();
    }
    for (int i = 0, x, y; i < m; ++i)
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
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (v == f)
        {
            continue;
        }
        if (dep[v] == -1)
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (dep[u] < low[v])
            {
                bridge.push_back(make_pair(u, v));
                bridgeSet.insert(make_pair(u, v));
                bridgeSet.insert(make_pair(v, u));
            }
        }
        else if (low[u] > dep[v])
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
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        bccno[u] = bccCnt;
        bcc[bccCnt].push_back(u);
        FOR(i, 0, G[u].size())
        {
            int v = G[u][i];
            if (bccno[v] == -1 && !bridgeSet.count(make_pair(u, v)))
            {
                q.push(v);
            }
        }
    }
}

int solve(int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        if (dep[i] == -1)
        {
            tarjan(i, -1);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (bccno[i] == -1)
        {
            floodFill(i);
        }
    }

    if (bccCnt == 1)
    {
        return 0;
    }
    FOR(i, 0, bridge.size())
    {
        PII it = bridge[i];
        int u = it.first, v = it.second;
        ++deg[bccno[u]];
        ++deg[bccno[v]];
    }
    int deg0Cnt = 0, deg1Cnt = 0;
    for (int i = 1; i <= bccCnt; ++i)
    {
        if (deg[i] == 0)
        {
            ++deg0Cnt;
        }
        else if (deg[i] == 1)
        {
            ++deg1Cnt;
        }
    }
    cout << deg0Cnt << ' ' << deg1Cnt << '\n';
    return deg0Cnt + (deg1Cnt + 1) / 2;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        init(n, m);
        cout << solve(n, m) << '\n';
    }
}