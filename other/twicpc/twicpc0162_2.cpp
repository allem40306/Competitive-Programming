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
const int MXS = 50;
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
int n, v;
int cnt;
vector<int> a;
char s[MXS], ans[50000][MXS];

void dfs(int idx, int val)
{
    if (idx == n)
    {
        if (val == v)
        {
            strcpy(ans[cnt++], s);
        }
        return;
    }
    FOR(i, 0, a[idx] + 1)
    {
        s[2 * idx] = char('0' + i);
        if (idx != n - 1)
            s[2 * idx + 1] = '^';
        dfs(idx + 1, val ^ i);
    }
}

int main()
{
    scanf("%d %d", &n, &v);
    a.resize(n);
    cnt = 0;
    FOR(i, 0, n) { scanf("%d", &a[i]); }
    dfs(0, 0);
    printf("%d\n", cnt);
    FOR(i, 0, cnt) { printf("%s=%d\n", ans[i], v); }
}
