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
vector<long long> v;

void dfs(set<long long> &s, int idx, int R, long long sum)
{
    if (idx >= R)
    {
        s.insert(sum);
        return;
    }
    dfs(s, idx + 1, R, sum);
    dfs(s, idx + 1, R, sum + v[idx]);
}

int main()
{
    IOS;
    int n;
    long long t, ans = 0;
    set<long long> s1, s2;
    cin >> n >> t;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        v.emplace_back(x);
    }
    dfs(s1, 0, n / 2, 0);
    dfs(s2, n / 2, n, 0);
    for (auto &x : s1)
    {
        auto it = s2.upper_bound(t - x);
        long long y = *(--it);
        if (x + y <= t)
            ans = max(ans, x + y);
    }
    cout << ans << '\n';
}
