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
map<LL, LL> tb;

LL query(LL x)
{
    if (tb.find(x) == tb.end())
        return 0;
    return tb[x];
}

void insert(LL x)
{
    if (tb.find(x) == tb.end())
        tb[x] = 1;
    else
        tb[x] += 1;
    return;
}

int main()
{
    IOS;
    int n;
    LL p, q;
    vector<LL> v;
    cin >> n >> p >> q;
    if ((p + q) % 2 == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    FOR(i, 0, n)
    {
        LL x;
        cin >> x;
        v.emplace_back(x);
    }
    LL tar = (p + q) / 2, cnt = 0, ans = 0;
    FORD(i, n - 1, -1)
    {
        if (v[i] == tar)
            ans += cnt;
        cnt += query(p - tar - v[i]);
        insert(v[i]);
    }
    cout << ans << '\n';
}
