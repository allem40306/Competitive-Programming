#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 105;
const int MXK = 20;
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
int n, m, k;
int ans = 0;
int a[MXN][2], b[MXK][2];
int cnt[MXN];

void dfs(int dep){
    if(dep==k)
    {
        int tmp = 0;
        FOR(i, 0, m) if (cnt[a[i][0]] && cnt[a[i][1]])++tmp;
        ans = max(ans, tmp);
        return;
    }
    ++cnt[b[dep][0]];
    dfs(dep + 1);
    --cnt[b[dep][0]];
    ++cnt[b[dep][1]];
    dfs(dep + 1);
    --cnt[b[dep][1]];
}

int main()
{
    IOS;
    cin >> n >> m;
    FOR(i, 0, m) cin >> a[i][0] >> a[i][1];
    cin >> k;
    FOR(i, 0, k) cin >> b[i][0] >> b[i][1];
    dfs(0);
    cout << ans << '\n';
}
