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
vector<LL> v;
LL ans, n;
int m;

void dfs(int idx, int cnt, LL cur)
{
    if (idx == (int)v.size())
    {
        if (cnt % 2)
            ans += n / cur;
        else
            ans -= n / cur;
        return;
    }
    dfs(idx + 1, cnt, cur);
    dfs(idx + 1, cnt + 1, cur / __gcd(cur, v[idx]) * v[idx]);
}

int main()
{
    IOS;
    while (cin >> n >> m)
    {
        v.clear();
        ans = n;
        FOR(i, 0, m)
        {
            LL x;
            cin >> x;
            v.emplace_back(x);
        }
        dfs(0, 0, 1);
        cout << n - ans << '\n';
    }
}
