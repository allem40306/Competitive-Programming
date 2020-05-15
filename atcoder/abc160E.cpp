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
    // IOS;
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<LL> R(a), G(b), C(c);
    FOR(i, 0, a) { cin >> R[i]; }
    FOR(i, 0, b) { cin >> G[i]; }
    FOR(i, 0, c) { cin >> C[i]; }
    sort(R.begin(), R.end(), greater<LL>());
    sort(G.begin(), G.end(), greater<LL>());
    FOR(i, 0, x) { C.push_back(R[i]); }
    FOR(i, 0, y) { C.push_back(G[i]); }
    sort(C.begin(), C.end(), greater<LL>());
    LL ans = 0;
    FOR(i, 0, x + y) { ans += C[i]; }
    cout << ans << '\n';
}
