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
const int MXN = 3e3 + 5;
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
int dp[MXN][MXN], pre[MXN][MXN];
int dir[3][2] = {{-1, -1}, {-1, 0}, {0, -1}};

int main()
{
    // IOS;
    string s, t;
    cin >> s >> t;
    FOR(i, 1, s.size() + 1) FOR(j, 1, t.size() + 1)
    {
        if (s[i - 1] == t[j - 1])
        {
            dp[i][j] = dp[i - 1][j - 1] + 1;
            pre[i][j] = 0;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            dp[i][j] = dp[i - 1][j];
            pre[i][j] = 1;
        }
        else
        {
            dp[i][j] = dp[i][j - 1];
            pre[i][j] = 2;
        }
    }
    vector<char> st;
    for (int i = (int)s.size(), j = (int)t.size(); i && j;)
    {
        // cout << i << ' ' << j << '\n';
        if (pre[i][j] == 0)
        {
            st.PB(s[i - 1]);
        }
        int tmp = dir[pre[i][j]][0];
        j += dir[pre[i][j]][1];
        i += tmp;
    }
    while (!st.empty())
    {
        cout << st.back();
        st.pop_back();
    }
    cout << '\n';
}
