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
const int MXN = 30;
const int MXD = 2500000 + 5;
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
int m,ans;
int d[MXN], cnt[MXD * 2 + 100];

void dfs(int i, int dis, int used)
{
    if (i==m)
    {
        ans = min(used, ans);
        return;
    }
    int tmp1 = dis + d[i], tmp2 = dis - d[i];
    cnt[tmp1] += 1;
    dfs(i + 1, tmp1, used + (cnt[tmp1] == 1));
    cnt[tmp1] -= 1;
    cnt[tmp2] += 1;
    dfs(i + 1, tmp2, used + (cnt[tmp2] == 1));
    cnt[tmp2] -= 1;
}

int main()
{
    // IOS;
    cin >> m;
    FOR(i, 0, m) { cin >> d[i]; }
    ans = m + 5;
    memset(cnt, 0, sizeof(cnt));
    cnt[MXD] = cnt[MXD + d[0]] = 1;
    dfs(1, MXD + d[0], 2);
    cout << ans << '\n';
}
