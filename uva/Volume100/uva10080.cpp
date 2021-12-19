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
const int MXV = 105;
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
int lhs, rhs, Left[MXV], G[MXV][MXV];
bitset<MXV> used;
bool dfs(int s)
{
    FOR(i, 0, rhs)
    {
        if (!G[s][i] || used[i])
        {
            continue;
        }
        used[i] = 1;
        if (Left[i] == -1 || dfs(Left[i]))
        {
            Left[i] = s;
            return true;
        }
    }
    return false;
}

int sol()
{
    int ret = 0;
    memset(Left, -1, sizeof(Left));
    FOR(i, 0, lhs)
    {
        used.reset();
        if (dfs(i))
            ++ret;
    }
    return ret;
}

int main()
{
    IOS;
    int n, m;
    double s, v, dis;
    double lx[MXV], rx[MXV], ly[MXV], ry[MXV];
    while (cin >> n >> m >> s >> v)
    {
        lhs = n;
        rhs = m;
        dis = s * s * v * v;
        FOR(i, 0, n) cin >> lx[i] >> ly[i];
        FOR(i, 0, m) cin >> rx[i] >> ry[i];
        memset(G, 0, sizeof(G));
        FOR(i, 0, n) FOR(j, 0, m)
        {
            if ((lx[i] - rx[j]) * (lx[i] - rx[j]) +
                (ly[i] - ry[j]) * (ly[i] - ry[j]) + EPS <= dis)
                {
                    G[i][j] = 1;
                    // cout << i << ' ' << j << '\n';
                }
        }
        cout << n - sol() << '\n';
    }
}
