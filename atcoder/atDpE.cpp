#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const LL INF = 1e10;
const int MXN = 1e5 + 1;
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

int main()
{
    // IOS;
    int N, W;
    vector<LL> dp(MXN, INF);
    cin >> N >> W;
    dp[0] = 0;
    FOR(i, 0, N)
    {
        LL v, w;
        cin >> w >> v;
        FORD(j, MXN - 1, v - 1) { dp[j] = min(dp[j], dp[j - v] + w); }
    }
    FORD(i, MXN - 1, 0 - 1)
    {
        if (dp[i] <= W)
        {
            cout << i << '\n';
            return 0;
        }
    }
}
