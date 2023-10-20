#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 2e5 + 5;
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
LD dp[MXN], sum[MXN];
int n, m, k;
bitset<MXN> isA;

LD f(LD x)
{
    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));
    FORD(i, n - 1, 0 - 1)
    {
        if (isA[i])
            dp[i] = x;
        else
            dp[i] = (sum[i + 1] - sum[i + m + 1]) / m + 1;
        sum[i] = sum[i + 1] + dp[i];
    }
    return dp[0];
}

int main()
{
    IOS;
    int x;
    cin >> n >> m >> k;
    isA.reset();
    FOR(i, 0, k)
    {
        cin >> x;
        isA[x] = 1;
    }
    LD L = 0, R = 4e18;
    for (int i = 0; i < 100 && L + 1e-6 < R; ++i)
    {
        LD M = (L + R) / 2;
        if (f(M) > M)
            L = M;
        else
            R = M;
    }
    if (L > 1e11)
        cout << "-1\n";
    else
        cout << fixed << setprecision(3) << L << '\n';
}
