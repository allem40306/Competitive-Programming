#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 1e4 + 5;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
int cnt = 0;
vector<int> G[MXV], c(MXV);
bitset<MXV> vis;

void dfs(int u)
{
    vis[u] = true;
    for (int v : G[u])
    {
        if (!vis[v])
        {
            dfs(v);
            if (c[v] != c[u])
            {
                ++cnt;
            }
        }
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    FOR(i, 2, n + 1)
    {
        int j;
        cin >> j;
        G[i].push_back(j);
        G[j].push_back(i);
    }
    FOR(i, 1, n + 1) { cin >> c[i]; }
    vis.reset();
    cnt = 1;
    dfs(1);
    cout << cnt << '\n';
}
