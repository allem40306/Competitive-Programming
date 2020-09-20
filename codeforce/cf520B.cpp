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
const int MXN = 1e4 + 5;
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

int main()
{
    IOS;
    int dis[MXN];
    int n, m;
    queue<int> q;
    memset(dis, -1, sizeof(dis));
    cin >> n >> m;
    q.push(n);
    dis[n] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        // cout << cur << ' ' << dis[cur] << '\n';
        if (cur == m)
        {
            cout << dis[cur] << '\n';
            return 0;
        }
        q.pop();
        if (cur - 1 > 0 && cur - 1 < MXN && dis[cur - 1] == -1)
        {
            dis[cur - 1] = dis[cur] + 1;
            q.push(cur - 1);
        }
        if (cur * 2 > 0 && cur * 2 < MXN && dis[cur * 2] == -1)
        {
            dis[cur * 2] = dis[cur] + 1;
            q.push(cur * 2);
        }
    }
}
