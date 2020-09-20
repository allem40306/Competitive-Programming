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
int n;
int arr[MXN];
bool dp[MXN][2];

int dfs(int k,int p)
{
    if(dp[k][p]>0){
        return dp[k][p];
    }
    int ans = 0;
    FOR(i, 0, n) if (k - arr[i] >= 0) { ans |= !dfs(k - arr[i], !p); }
    return dp[k][p] = ans;
}

int main()
{
    IOS;
    int k;
    cin >> n >> k;
    FOR(i, 0, n) { cin >> arr[i]; }
    if (dfs(k, 0) == 0)
    {
        cout << "Second\n";
    }
    else
    {
        cout << "First\n";
    }
}
