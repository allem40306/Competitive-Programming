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
const int MXV = 0;
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

int main()
{
    IOS;
    int t;
    cin >> t;
    vector<LL> a, b;
    while (t--)
    {
        int n;
        LL suma = 0, sumb = 0;
        cin >> n;
        a.resize(n);
        b.resize(n);
        FOR(i, 0, n)
        {
            cin >> a[i] >> b[i];
            suma += a[i];
            sumb += b[i];
        }
        LL ans = min(suma, sumb);
        FOR(i, 0, n) { ans = min(ans, (suma - a[i]) + (sumb - b[i])); }
        cout << ans << '\n';
    }
}
