#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 15;
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
int dp[MXN][MXN], to[MXN][MXN];
int x[MXN];

int f(int L, int R)
{
    if (L == R)
        return dp[L][R] = 0;
    if (dp[L][R] != -1)
        return dp[L][R];
    dp[L][R] = INT_MAX;
    for (int i = L; i < R; ++i)
    {
        int res = f(L, i) + f(i + 1, R) + x[L] * x[i + 1] * x[R + 1];
        if(res < dp[L][R])
        {
            dp[L][R] = res;
            to[L][R] = i;
        }
    }
    return dp[L][R];
}

void dfs(int L, int R)
{
    if(L==R)
    {
        cout << "A" << L + 1;
        return;
    }
    if(L==R-1)
    {
        cout << "(A" << L + 1 << " x A" << R + 1 << ")";
        return;
    }
    cout << "(";
    dfs(L, to[L][R]);
    cout << " x ";
    dfs(to[L][R] + 1,R);
    cout << ")";
}

int main()
{
    IOS;
    int n, ti = 0;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> x[i] >> x[i + 1];
        memset(dp, -1, sizeof(dp));
        cout << "Case " << ++ti << ": ";
        f(0, n - 1);
        dfs(0, n - 1);
        cout << '\n';
    }
}
