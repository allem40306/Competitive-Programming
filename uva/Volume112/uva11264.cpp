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
const int MXN = 0;
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
    int t;
    vector<int> coins;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        coins.resize(n);
        FOR(i, 0, n) { cin >> coins[i]; }
        int sum = 0, ans = 1;
        FOR(i, 0, n - 1)
        {
            if (sum + coins[i] < coins[i + 1])
            {
                ++ans;
                sum += coins[i];
            }
        }
        cout << ans << '\n';
    }
}
