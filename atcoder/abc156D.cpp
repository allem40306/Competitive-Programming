/*
source: ABC 156 D Bouquet
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
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

LL pow2(LL n)
{
    LL tmp = 2, res = 1;
    for (; n > 0; n >>= 1)
    {
        if ((n & 1) != 0)
        {
            res = (res * tmp) % MOD;
        }
        tmp = (tmp * tmp) % MOD;
    }
    return res;
}

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

LL sol(LL m, LL n)
{
    LL x = 1, y = 1, tmp1, tmp2;
    for (LL i = m; i > m - n; --i){ x = (x * i) % MOD; }
    for (LL i = 1; i <= n; ++i){ y = (y * i) % MOD; }
    extgcd(y, MOD, tmp1, tmp2);
    x = (x * tmp1);
    return (x + MOD) % MOD;
}

int main()
{
    IOS;
    LL n, a, b;
    cin >> n >> a >> b;
    LL ans = (pow2(n) - 1 + MOD) % MOD;
    ans -= sol(n, a);
    ans -= sol(n, b);
    while(ans < MOD)
    {
        ans += MOD;
    }
    cout << (ans + MOD) % MOD << '\n';
}
