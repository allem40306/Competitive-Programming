#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n + 1, 0);
    FOR(i, 1, n + 1)
    {
        FOR(j, i + 1, n + 1)
        {
            int mn = min({abs(i - j), abs(i - x) + abs(j - y) + 1,
                          abs(i - y) + abs(j - x) + 1});
            ++ans[mn];
        }
    }
    FOR(i, 1, n) { cout << ans[i] << "\n"; }
}
