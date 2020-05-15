/*
source: ABC 156 F Modularness
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 5005;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
vector<LL> d(MXN), a(MXN), zero(MXN), sum(MXN);

LL sol(LL k, LL n, LL x, LL m)
{
    x %= m;
    zero[0] = sum[0] = 0;
    FOR(i, 1, k + 1)
    {
        a[i] = d[i] % m;
        zero[i] = zero[i - 1] + (a[i] == 0);
        sum[i] = sum[i - 1] + a[i];
    }
    LL ans = n - 1;
    // cout << zero[k] << ' ' << sum[k] << '\n';
    ans -= ((n - 1) / k) * zero[k] + zero[(n - 1) % k];
    ans -= (((n - 1) / k) * sum[k] + sum[(n - 1) % k] + x) / m - x / m;
    return ans;
}

int main()
{
    IOS;
    int k, q;
    cin >> k >> q;
    FOR(i, 1, k + 1) { cin >> d[i]; }
    while(q--)
    {
        LL n, x, m;
        cin >> n >> x >> m;
        cout << sol(k, n, x, m) << '\n';
    }
}
