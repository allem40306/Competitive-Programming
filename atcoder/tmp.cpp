/*
source: AtCoder Beginner Contest 152 E
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 1000005;
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

int main()
{
    IOS;
    string s;   
    vector<LL> n(MXN, 0);
    static LL dp[MXN][2];
    cin >> s;
    s = '0' + s;
    FOR(i, 0, s.size())
    {
        n[i] = int(s[s.size() - 1 - i] - '0');
    }
    dp[0][0] = n[0];
    dp[0][1] = (10 - n[0]);
    FOR(i, 1, s.size())
    {
        dp[i][0] = min(dp[i - 1][0] + n[i], dp[i - 1][1] + n[i] + 1);
        dp[i][1] = min(dp[i - 1][0] + (10 - n[i]), dp[i - 1][1] + 10 - (n[i] + 1));
    }
    cout << min(dp[(int)s.size() - 1][0], dp[(int)s.size() - 1][1]) << '\n';
}
