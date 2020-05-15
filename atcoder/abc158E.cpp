#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<LL>;
using VVI = vector<VI>;
const int INF = 1e9;
const int MXN = 2e5 + 5;
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

int main()
{
    // IOS;
    int n, p, tmp = 0, t = 1;
    LL ans = 0;
    string s;
    VI cnt(MXN, 0);
    cin >> n >> p >> s;
    if (p == 2 || p == 5)
    {
        FOR(i, 0, n)
        {
            if ((s[i] - '0') % p == 0)
            {
                ans += (i + 1);
            }
        }
    }
    else
    {
        cnt[0] = 1;
        FORD(i, n - 1, 0 - 1)
        {
            tmp = (tmp + ((int)(s[i] - '0') * t)) % p;
            ans += cnt[tmp]++;
            t = (t * 10) % p;
        }
    }
    cout << ans << '\n';
}
