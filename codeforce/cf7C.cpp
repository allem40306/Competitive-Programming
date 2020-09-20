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
const int MXN = 1e6 + 5;
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

LL extgcd(LL a, LL b, LL c, LL &x, LL &y)
{
    LL d = a;
    if (b)
    {
        d = extgcd(b, a % b, c, y, x), y -= (a / b) * x;
    }
    else
        x = c / a, y = 0;
    return d;
}

int main()
{
    IOS;
    LL a, b, c;
    cin >> a >> b >> c;
    int GCD = __gcd(a, b);
    if (c % GCD)
    {
        cout << -1 << '\n';
        return 0;
    }
    LL x, y;
    extgcd(a, b, -c, x, y);
    cout << x << ' ' << y << '\n';
}
