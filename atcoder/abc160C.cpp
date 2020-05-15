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
    int k, n;
    cin >> k >> n;
    vector<int> v(n);
    FOR(i, 0, n) { cin >> v[i]; }
    int mx = v[0] + (k - v[n - 1]);
    FOR(i, 1, n) { mx = max(mx, v[i] - v[i - 1]); }
    cout << k - mx << '\n';
}
