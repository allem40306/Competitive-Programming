#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 65;
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

LL ans[MXN][2];
int main()
{
    IOS;
    ans[0][0] = ans[0][1] = 1;
    int n;
    string s;
    cin >> n;
    FOR(i, 1, n + 1)
    {
        cin >> s;
        if (s == "OR")
        {
            ans[i][0] = ans[i - 1][0];
            ans[i][1] = ans[i - 1][0] + 2 * ans[i - 1][1];
        }
        else
        {
            ans[i][0] = 2 * ans[i - 1][0] + ans[i - 1][1];
            ans[i][1] = ans[i - 1][1];
        }
    }
    cout << ans[n][1] << '\n';
}
