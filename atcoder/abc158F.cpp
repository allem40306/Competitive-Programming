#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 2e5;
const int MXV = 0;
const LL MOD = 998244353;
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

vector<int> bits(MXN, 0);

void update(int x, int val, int n)
{
    for (; x <= n; x += (x & (-x)))
    {
        bits[x] = max(bits[x], val);
    }
}

int query(int x)
{
    int ans = 0;
    for (; x > 0; x -= (x & (-x)))
    {
        ans = max(ans, bits[x]);
    }
    return ans;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<PII> data(n);
    vector<LL> dp(n + 1, 0);
    vector<int> res(n, 0);
    FOR(i, 0, n) { cin >> data[i].F >> data[i].S; }
    sort(data.begin(), data.end());
    dp[n] = 1;
    FORD(i, n - 1, 0 - 1)
    {
        res[i] = i;
        int pos = lower_bound(data.begin(), data.end(),
                              MP(data[i].F + data[i].S, 0)) -
                  data.begin() - 1;
        res[i] = max(res[i], query(pos + 1));
        update(i + 1, res[i], n);
        if(res[i] + 1 < (int)dp.size())
        {
            dp[i] = (dp[i + 1] + dp[res[i] + 1]) % MOD;
        }
        else
        {
            dp[i] = (dp[i + 1] + 1) % MOD;
        }
    }
    cout << dp[0] << '\n';
}
