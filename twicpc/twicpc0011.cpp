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
const LL MOD = 1e9 + 7;
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

LL POW2(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

LL trans(string s)
{
    LL ret = 0;
    FOR(i, 0, s.size())
    {
        ret = ret * 10 % MOD;
        ret += s[i] - '0';
        ret = (ret % MOD + MOD) % MOD;
    }
    return ret % MOD;
}

int main()
{
    IOS;
    string x, y;
    LL a, b;
    cin >> x >> a >> y >> b;
    cout << POW2(trans(x), a) * POW2(trans(y), b) % MOD;
}
