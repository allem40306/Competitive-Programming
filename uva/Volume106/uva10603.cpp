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
const int MXN = 2e2 + 5;
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

struct Data
{
    int v[3], tot;
    bool operator<(const Data &rhs) const { return tot > rhs.tot; }
};

int ans[MXN], cap[3];
bool vis[MXN][MXN];

void update(const Data &d)
{
    FOR(i, 0, 3)
    {
        int u = d.v[i];
        if (ans[u] == -1 || ans[u] > d.tot)
        {
            ans[u] = d.tot;
        }
    }
}

void bfs(int a, int b, int c, int d)
{
    priority_queue<Data> pq;
    memset(ans, -1, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    cap[0] = a;
    cap[1] = b;
    cap[2] = c;
    Data cur;
    cur.v[0] = 0;
    cur.v[1] = 0;
    cur.v[2] = c;
    cur.tot = 0;
    vis[0][0] = true;
    pq.push(cur);
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        update(cur);
        if (ans[d] >= 0)
        {
            break;
        }
        FOR(i, 0, 3) FOR(j, 0, 3) if (i != j)
        {
            if (cur.v[i] == 0 || cur.v[j] == cap[j])
            {
                continue;
            }
            int amount = min(cap[j], cur.v[i] + cur.v[j]) - cur.v[j];
            Data tmp = cur;
            tmp.tot = cur.tot + amount;
            tmp.v[i] -= amount;
            tmp.v[j] += amount;
            if (vis[tmp.v[0]][tmp.v[1]] == false)
            {
                vis[tmp.v[0]][tmp.v[1]] = true;
                pq.push(tmp);
            }
        }
    }
    while (d >= 0)
    {
        if (ans[d] >= 0)
        {
            cout << ans[d] << ' ' << d << '\n';
            break;
        }
        --d;
    }
}

int main()
{
    // IOS;
    int t, a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        bfs(a, b, c, d);
    }
}
