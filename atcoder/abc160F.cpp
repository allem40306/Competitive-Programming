#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VLL = vector<LL>;
using VVI = vector<VI>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 2e5 + 5;
const LL MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

VLL fac, invfac;

LL pow2(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if ((b & 1) != 0)
        {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void init(int n)
{
    fac.resize(n + 1);
    invfac.resize(n + 1);
    fac[0] = 1;
    FOR(i, 1, n + 1) { fac[i] = (fac[i - 1] * i) % MOD;}
    invfac[n] = pow2(fac[n], MOD - 2);
    FORD(i, n - 1, 0 - 1) { invfac[i] = (invfac[i + 1] * (i + 1)) % MOD;}
}

int n;
VVI G;
VLL dp, sz, ans;

LL C(int m, int n) { return (fac[m] * invfac[n]) % MOD * invfac[m - n] % MOD; }

void dfs1(int u, int p)
{
    for (int v : G[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] = (dp[u] * dp[v] % MOD) * C(sz[u] - 1, sz[v]) % MOD;
    }
}

void dfs2(int u, int p)
{
    for (int v : G[u])
    {
        if (v == p)
        {
            continue;
        }
        ans[v] = ans[u] * pow2(C(n - 1, sz[v]) * dp[v] % MOD, MOD - 2) % MOD;
        ans[v] =
            (ans[v] * dp[v] % MOD) * C(n - 1, n - sz[v]) % MOD;
        dfs2(v, u);
    }
}

int main()
{
    IOS;
    cin >> n;
    G.resize(n + 5);
    dp.resize(n + 5, 1);
    sz.resize(n + 5, 1);
    ans.resize(n + 5);
    init(n);
    FOR(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(1, -1);
    // FOR(i, 1, n + 1) { cout << dp[i] << '\n'; }
    ans[1] = dp[1];
    dfs2(1, -1);
    FOR(i, 1, n + 1) { cout << ans[i] << '\n'; }
}
