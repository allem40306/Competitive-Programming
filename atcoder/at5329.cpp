/*
source: ABC 153 E Crested Ibis vs Monster 
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 20005;
const int MXV = 0;
#define MP  make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
vector<int> dp(MXN, INF);

void sol(int a, int b)
{
    for(int i = a; i < MXN; ++i)
    {
        dp[i] = min(dp[i], dp[i - a] + b);
    }
}

int main()
{
    IOS;
    int h, n;
    cin >> h >> n;
    dp[0] = 0;
    for (int i = 0, a, b; i < n; ++i)
    {
        cin >> a >> b;
        sol(a, b);
    }
    cout << *min_element(dp.begin() + h, dp.begin() + MXN) << '\n';
}
