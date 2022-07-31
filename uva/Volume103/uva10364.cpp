#pragma GCC optimize(2)
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
vector<int> v(MXN);
bitset<MXN> used;
int n,sum, avg;

bool dfs(int curSide, int curLength, int idx)
{
    // cout << curSide << ' ' << curLength << ' ' << idx << '\n';
    if(curLength == avg)
    {
        if(curSide == 3)
            return true;
        ++curSide;
        curLength = idx = 0;
    }
    for (int i = idx; i < n; ++i)
    {
        if(used[i] || curLength + v[i] > avg)
            continue;
        used[i] = true;
        if(dfs(curSide, curLength + v[i], i + 1))
            return true;
        used[i] = false;
    }
    return false;
}

void solve()
{
    sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.begin() + n, greater<int>());
    avg = sum / 4;
    used.reset();
    if (sum % 4 || v[0] > avg || !dfs(0, 0, 0))
        cout << "no\n";
    else
        cout << "yes\n";
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
