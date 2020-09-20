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
const int MXN = 1e5 + 5;
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
    IOS;
    int N, W;
    vector<LL> dp(MXN);
    cin >> N >> W;
    fill(dp.begin(), dp.end(), 0);
    FOR(i, 0, N)
    {
        LL v;
        int w;
        cin >> w >> v;
        FORD(j, W, w - 1) { dp[j] = max(dp[j], dp[j - w] + v); }
    }
    cout << *max_element(dp.begin(), dp.begin() + W + 1) << '\n';
}
