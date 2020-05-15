#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
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

LL f(LL n)
{
    if (n < 2)
    {
        return 0;
    }
    return n * (n - 1) / 2;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    LL ans = 0;
    vector<LL> a(n, 0), cnt(n + 1, 0);
    FOR(i, 0, n)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    FOR(i, 0, n + 1) { ans += f(cnt[i]); }
    FOR(i, 0, n) { cout << ans - f(cnt[a[i]]) + f(cnt[a[i]] - 1) << '\n'; }
}
