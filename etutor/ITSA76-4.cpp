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
vector<int> coins = {500, 100, 50, 10, 5, 1}, cnt(6);

int main()
{
    IOS;
    int t;
    cin >> t;
    FOR(ti, 0, t)
    {
        int n, ans = 0;
        cin >> n;
        n = 1000 - n;
        FOR(i, 0, 6)
        {
            cnt[i] = 0;
            while (n >= coins[i])
            {
                ++cnt[i];
                if (i > 1)
                {
                    ++ans;
                }
                n -= coins[i];
            }
        }
        cout << ans << '\n';
        FOR(i, 0, 6) { cout << cnt[i] << " \n"[i == 5]; }
    }
}
