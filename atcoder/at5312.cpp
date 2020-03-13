/*
source: ABC 156 E Roaming
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 200005;
const int MXV = 0;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

LL extgcd(LL a, LL b, LL &x, LL &y)
{
    LL d = a;
    if (b)
    {
        d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    }
    else
        x = 1, y = 0;
    return d;
} // ax+by=1 ax同餘 1 mod b

vector<LL> fac(MXN, 0), invfac(MXN, 0);

LL inv(LL a)
{
    LL x, y, b = MOD;
    extgcd(a, b, x, y);
    while(x >= MOD)
    {
        x -= MOD;
    }
    while(x < 0)
    {
        x += MOD;
    }
    return x;
}

void build()
{
    fac[0] = fac[1] = 1;
    invfac[0] = invfac[1] = 1;
    FOR(i, 2, MXN)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
        invfac[i] = inv(fac[i]);
    }
}

LL C(LL m, LL n)
{
    LL res = fac[m];
    res = (res * invfac[n]) % MOD;
    res = (res * invfac[m - n]) % MOD;
    return res;
}

int main()
{
    IOS;
    build();
    int n, k;
    cin >> n >> k;
    k = min(k, n - 1);
    LL ans = 0;
    FOR(i, 0, k + 1) { ans = (ans + (C(n, i) * C(n - 1, n - i - 1) % MOD)) % MOD; }
    cout << ans << '\n';
}
