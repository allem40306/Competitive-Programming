/*
source: ABC 154 D Dice in Line
*/
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
    int n, k;
    double ans = 0;
    cin >> n >> k;
    vector<double> v(n + 1, 0);
    FOR(i, 1, n + 1)
    {
        cin >> v[i];
        v[i] = (1 + v[i]) * 0.5;
        v[i] += v[i - 1];
    }
    FOR(i, k, n + 1)
    {
        ans = max(ans, v[i] - v[i - k]);
    }
    cout << fixed << setprecision(8) << (double)ans << '\n';
}
