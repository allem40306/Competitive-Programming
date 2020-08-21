#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e4 + 5;
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
int n, m;
int timeCnt;
vector<int> dep(MXV), low(MXV);
vector<int> G[MXV];
vector<int> ans, cnt(MXV);

void init()
{
    timeCnt = 0;
    ans.clear();
    fill(cnt.begin(), cnt.end(), 0);
    fill(dep.begin(), dep.end(), 0);
    fill(low.begin(), low.end(), 0);
    FOR(i, 1, MXV) { G[i].clear(); }
}

void dfs(int u, int f)
{
    int child = 0;
    dep[u] = low[u] = ++timeCnt;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (dep[v] == 0)
        {
            ++child;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dep[u])
            {
                ++cnt[u];
            }
        }
        else if (dep[v] < dep[u] && v != f)
        {
            low[u] = min(low[u], dep[v]);
        }
    }
    if (f == -1 && child > 1)
    {
        ans.push_back(u);
    }
    else if (f != -1 && cnt[u] > 0)
    {
        ans.push_back(u);
        ++cnt[u];
    }
}

void tarjan()
{
    FOR(i, 1, MXV) if (dep[i] == 0) { dfs(i, -1); }
}

void sol()
{
    if (!ans.size())
    {
        printf("  No SPF nodes\n");
        return;
    }
    sort(ans.begin(), ans.end());
    FOR(i, 0, ans.size())
    {
        printf("  SPF node %d leaves %d subnets\n", ans[i], cnt[ans[i]]);
    }
}

int main()
{
    int u, v, ti = 0;
    while (scanf("%d", &u), u)
    {
        init();
        do
        {
            scanf("%d", &v);
            G[u].push_back(v);
            G[v].push_back(u);
        } while (scanf("%d", &u), u);
        tarjan();
        printf("Network #%d\n", ++ti);
        sol();
        printf("\n");
    }
}