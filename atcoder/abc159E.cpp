#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<VI>;
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

void update(vector<int> &v, int x, int h)
{
    v.clear();
    v.push_back(0);
    int idx = 1;
    while (x)
    {
        if ((x & 1) != 0)
        {
            v.push_back(idx);
        }
        x >>= 1;
        ++idx;
    }
    v.push_back(h);
}

int main()
{
    // IOS;
    int h, w, k;
    cin >> h >> w >> k;
    VVI sum(h + 1, VI(w + 1, 0));
    FOR(i, 1, h + 1)
    {
        string s;
        cin >> s;
        FOR(j, 1, w + 1)
        {
            sum[i][j] = (int)(s[j - 1] - '0');
            sum[i][j] =
                sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int ans = h * w;
    vector<int> hs;
    FOR(state, 0, (1 << (h - 1)))
    {
        int cur = __builtin_popcount(state);
        bool ok = true;
        int j2 = 0;
        update(hs, state, h);
        FOR(j, 1, w + 1)
        {
            int wmax = 0;
            FOR(i, 1, hs.size())
            {
                wmax = max(wmax, sum[hs[i]][j] - sum[hs[i]][j2] -
                                     sum[hs[i - 1]][j] + sum[hs[i - 1]][j2]);
            }
            // cout << j << ' ' << wmax << '\n';
            if (wmax > k)
            {
                if (j == 1)
                {
                    ok = false;
                    break;
                }
                ++cur;
                j2 = j - 1;
            }
        }
        if (ok)
        {
            // cout << state << ' ' << cur << '\n';
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';
}
