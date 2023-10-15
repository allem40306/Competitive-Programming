#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 3e5 + 5;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define lowbit(x) ((x) & -(x))
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
LL BIT[MXN];

void update(int x)
{
    for (; x < MXN; x += lowbit(x))
        BIT[x] += 1;
}

int query(int x)
{
    LL ans = 0;
    for (; x > 0; x -= lowbit(x))
        ans += BIT[x];
    return ans;
}

LL a[MXN], res[MXN];
int main()
{
    IOS;
    int n;
    res[0] = 0;
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> a[i];
        a[i] += 1;
        res[0] += i - query(a[i] - 1);
        update(a[i]);
    }
    FOR(i, 1, n)
    {
        int diff = (n - a[i - 1]) - (a[i - 1] - 1);
        res[i] = res[i - 1] + diff;
    }
    FOR(i, 0, n) cout << res[i] << '\n';
}
