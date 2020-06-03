#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VLL = vector<LL>;
using VVI = vector<VI>;
using VVLL = vector<VLL>;
const int INF = 1e9;
const int MXN = 5005;
const int MXV = 0;
const LL MOD = 1e9 + 7;
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

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    VI s(n + 1);
    // lsum[x]: each j<=i and c[j]=x
    // rsum[x]: each j>i and c[j]=x
    VLL lsum(n + 1, 0), rsum(n + 1, 0);
    VVLL num(n + 1, VLL(n + 1, 0));
    FOR(i, 1, n + 1)
    {
        cin >> s[i];
        ++rsum[s[i]];
    }
    FOR(i, 1, m + 1)
    {
        int f, h;
        cin >> f >> h;
        FOR(j, h, n + 1) { ++num[f][j]; }
    }
    PLL ans = MP(0, 0);
    FOR(i, 0, n + 1)
    {
        int x = s[i];
        if (i)
        {
            ++lsum[x];
            --rsum[x];
        }
        LL ls = lsum[x], rs = rsum[x];
        PLL tmp = MP(0, 1);
        if (i)
        {
            LL cnt1 = num[x][ls] - num[x][ls - 1];
            if (cnt1 == 0)
            {
                continue;
            }
            LL cnt2 = num[x][rs] - (ls <= rs);
            ++tmp.F;
            tmp.S = (tmp.S * cnt1) % MOD;
            if (cnt2)
            {
                ++tmp.F;
                tmp.S = (tmp.S * cnt2) % MOD;
            }
        }
        FOR(x2, 1, n + 1)
        {
            if (x == x2)
            {
                continue;
            }
            LL cnt1 = num[x2][lsum[x2]];
            LL cnt2 = num[x2][rsum[x2]];
            if (cnt1 > cnt2)
            {
                swap(cnt1, cnt2);
            }
            if (cnt2)
            {
                ++tmp.F;
                if (cnt1 == 0)
                {
                    tmp.S = tmp.S * cnt2 % MOD;
                }
                else if (cnt2 == 1)
                {
                    tmp.S = tmp.S * 2LL % MOD;
                }
                else
                {
                    ++tmp.F;
                    tmp.S = (tmp.S * cnt1) % MOD * (cnt2 - 1) % MOD;
                }
            }
        }
        if (ans.F < tmp.F)
        {
            ans = tmp;
        }
        else if (tmp.F == ans.F)
        {
            ans.S = (ans.S + tmp.S) % MOD;
        }
    }
    cout << ans.F << ' ' << ans.S << '\n';
}
