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
LL B, N, P;

LL fpow(LL a, LL b, LL c)
{
    LL res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % c;
        a = (a * a) % c;
    }
    return res;
}

LL BSGS(LL a, LL b, LL p)
{
    a %= p;
    b %= p;
    if (a == 0)
        return b == 0 ? 1 : -1;
    if (b == 1)
        return 0;
    map<LL, LL> tb;
    LL sq = ceil(sqrt(p - 1)), inv = fpow(a, p - sq - 1, p);
    tb[1] = sq;
    for (LL i = 1, tmp = 1; i < sq; ++i)
    {
        tmp = (tmp * a) % p;
        if (!tb.count(tmp))
            tb[tmp] = i;
    }
    for (LL i = 0; i < sq; ++i)
    {
        if (tb.count(b))
        {
            LL res = tb[b];
            return i * sq + (res == sq ? 0 : res);
        }
        b = (b * inv) % p;
    }
    return -1;
}

int main()
{
    IOS;
    while (cin >> P >> B >> N)
    {
        LL ans = BSGS(B, N, P);
        if (ans == -1)
            cout << "no solution\n";
        else
            cout << ans << '\n';
    }
}
