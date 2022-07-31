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
vector<int> v;
int sz;
long long ans;

void dfs(int idx, long long sum, long long cur)
{
    // cout << sum << ' ' << cur << '\n';
    if (idx == sz)
    {
        ans += sum + cur;
        return;
    }
    dfs(idx + 1, sum, cur * 10 + v[idx]); // not to choose +
    dfs(idx + 1, sum + cur, v[idx]);      // choose +
}

int main()
{
    IOS;
    long long n;
    cin >> n;
    while (n)
    {
        v.emplace_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    sz = (int)v.size();
    ans = 0;
    dfs(0, 0, 0);
    cout << ans / 2 << '\n';
}
