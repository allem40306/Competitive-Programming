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
    int n, k;
    vector<pair<int, int>> v;
    cin >> n >> k;
    FOR(i, 1, n + 1)
    {
        int x;
        cin >> x;
        if (x < k)
            v.emplace_back(MP(x, i));
    }
    if(!v.size())
    {
        cout << -1 << '\n';
        return 0;
    }
    sort(v.rbegin(), v.rend());
    cout << v[0].S << '\n';
}
