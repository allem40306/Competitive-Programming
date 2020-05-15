/*
source: ABC 151 E Max-Min Sums 
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
const LL MOD = 1e9 + 7;
const int MXN = 100005;
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

int main()
{
    IOS;
    int n, k;
    vector<int> v;
    pre();

    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    LL ans = 0;

    for (int i = k - 1; i < n; ++i)
    {
        LL cnt = choose(i, k - 1);
        // cout << i << ' ' << k - 1 << ' ' << cnt << ' ' << v[i] << '\n';
        LL tmp = ((v[i] % MOD) * cnt) % MOD;
        ans = (ans + tmp) % MOD;
    }

    for (int i = n - k; i >= 0; --i)
    {
        LL cnt = choose(n - i - 1, k - 1);
        // cout << n - i - 1 << ' ' << k - 1 << ' ' << cnt << ' ' << v[i] << '\n';
        LL tmp = ((v[i] % MOD) * cnt) % MOD;
        ans = (ans - tmp + MOD) % MOD;
    }

    cout << ans << '\n';
}