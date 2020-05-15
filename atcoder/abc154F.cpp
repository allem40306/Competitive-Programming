/*
source: ABC 154 F Many Many Paths
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 2e6 + 5;
const int MXV = 0;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
LL comb[MXN], invcomb[MXN];
 
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
 
void pre()
{
    comb[0] = 1;
    invcomb[0] = 1;
    for(int i = 1; i < MXN; ++i)
    {
        comb[i] = (comb[i - 1] * i) % MOD;
        invcomb[i] = inv(comb[i]);
    }
}
 
LL choose(int m, int n)
{
    LL ans = comb[m];
    ans = (ans * invcomb[m - n]) % MOD;
    ans = (ans * invcomb[n]) % MOD;
    return ans;
}

LL G(int m, int n) { return choose((m + 1) + (n + 1), n + 1) - 1; }

int main()
{
    IOS;
    pre();

    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1;
    --c1;

    LL ans = G(r2, c2) - G(r2, c1) - G(r1, c2) + G(r1, c1);
    while(ans <= 0)
    {
        ans += MOD;
    }
    ans %= MOD;
    cout << ans << '\n';
}
