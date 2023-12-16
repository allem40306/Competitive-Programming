#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 1e6 + 5;
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
#define lowbit(x) (x & (-x))
int sum[MXN << 1], num[MXN], ans[MXN];

void update(int x, int val)
{
    for (; x < (MXN << 1); x += lowbit(x))
    {
        sum[x] += val;
    }
}

int query(int x)
{
    int res = 0;
    for (; x > 0; x -= lowbit(x))
        res += sum[x];
    return res;
}

int main()
{
    // IOS;
    int t, n, m, x;
    cin >> t;
    while (t--)
    {
        memset(sum, 0, sizeof(sum));
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            num[i] = n - i + 1;
            update(num[i], 1);
        }
        int cnt = n;
        for (int i = 0; i < m; ++i)
        {
            cin >> x;
            ans[i] = query(cnt) - query(num[x]);
            update(num[x], -1);
            num[x] = ++cnt;
            update(num[x], 1);
        }
        FOR(i, 0, m) cout << ans[i] << " \n"[i == m - 1];
    }
}
