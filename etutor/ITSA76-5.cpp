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

void output(LL x, LL y)
{
    LL gcd = __gcd(x, y);
    cout << x / gcd << '/' << y / gcd << '\n';
}

int main()
{
    IOS;
    int t;
    cin >> t;
    FOR(ti, 0, t)
    {
        LL a, b, c, d;
        char ch;
        cin >> a >> ch >> b >> ch >> c >> ch >> d;
        a *= d;
        c *= b;
        b *= d;
        d = b;
        output(a + c, b);
        output(a - c, b);
        output(a * c, b * d);
        output(a, c);
    }
}
