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
    LL n, a, b, x = 0, y;
    vector<int> ans;
    bool ok = false;
    cin >> n >> a >> b;
    while (1)
    {
        if(a*x>n)
        {
            break;
        }
        if ((n - a * x) % b == 0)
        {
            ok = true;
            y = (n - a * x) / b;
            break;
        }
        ++x;
    }
    if(!ok)
    {
        cout << "-1\n";
        return 0;
    }
    while (a * x + b * y != n)
        ;
    FOR(i, 0, x) FOR(j, 0, a) { ans.PB((j == 0 ? (i + 1) * a : i * a + j)); }
    FOR(i, 0, y) FOR(j, 0, b)
    {
        ans.PB((j == 0 ? (i + 1) * b : i * b + j) + a * x);
    }
    FOR(i, 0, ans.size()) { cout << ans[i] << " \n"[i == (int)ans.size() - 1]; }
}
