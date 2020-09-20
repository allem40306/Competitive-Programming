#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9+7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> h(n+5),dp(n+5);
    FOR(i,0,n){cin >> h[i];}
    fill(dp.begin(),dp.end(),INF);
    dp[0] = 0;
    FOR(i,1,n)FOR(j,1,3)
    {
        if(i-j<0)
        {
            break;
        }
        dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
    cout << dp[n - 1] << '\n';
}
