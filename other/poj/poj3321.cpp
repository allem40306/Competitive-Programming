#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 1e5 + 5;
const ULL MOD = 10009;
const ULL seed = 31;
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
int n, ti;
vector<vector<int>> G(MXV);
vector<int> L(MXV), R(MXV), sum(MXV), a(MXV);
bitset<MXN> vis, apple;

inline void dfs(int u)
{
    vis[u] = 1;
    L[u] = ++ti;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (!vis[v])
        {
            dfs(v);
        }
    }
    R[u] = ti;
}

inline void update(int x, int v)
{
    for (; x <= n; x += (x & (-x)))
    {
        sum[x] += v;
    }
}

inline int query(int x)
{
    int ans = 0;
    for (; x > 0; x -= (x & (-x)))
    {
        ans += sum[x];
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    FOR(i, 1, n + 1) { G[i].clear(); }
    FOR(i, 1, n)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vis.reset();
    ti = 0;
    dfs(1);
    apple.set();
    FOR(i, 1, n + 1) { update(L[i], 1); }

    int m;
    scanf("%d", &m);
    FOR(i, 0, m)
    {
        int x;
        char ch;
        scanf(" %c %d", &ch, &x);
        if (ch == 'Q')
        {
            printf("%d\n", query(R[x]) - query(L[x] - 1));
        }
        else
        {
            if (apple[x])
            {
                update(L[x], -1);
            }
            else
            {
                update(L[x], 1);
            }
            apple[x] = !apple[x];
        }
    }
}