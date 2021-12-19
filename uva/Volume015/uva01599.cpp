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
const int MXV = 1e5 + 5;
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
struct Edge
{
    int from, to, c;
    Edge(int _from, int _to, int _c) : from(_from), to(_to), c(_c){};
};
vector<Edge> E;
vector<int> G[MXV];
int n, m;
int level[MXV], ans[MXV];
bitset<MXV> vis;

void bfs1(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (int i : G[s])
        {
            Edge &e = E[i];
            int t = e.from ^ e.to ^ s;
            if (level[t] != -1)
                continue;
            level[t] = level[s] + 1;
            q.push(t);
        }
    }
}

void bfs2(int s)
{
    memset(ans, -1, sizeof(ans));
    queue<int> q;
    vis.reset();
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        if (level[s] == 0)
            continue;
        int minC = 1e9 + 1;
        for (int i : G[s])
        {
            Edge &e = E[i];
            int t = e.from ^ e.to ^ s;
            if (level[t] + 1 == level[s])
            {
                minC = min(minC, e.c);
            }
        }
        int dis = level[1] - level[s];
        if (dis >= 0 && (ans[dis] == -1 || ans[dis] > minC))
        {
            ans[dis] = minC;
        }
        for (int i : G[s])
        {
            Edge &e = E[i];
            int t = e.from ^ e.to ^ s;
            if (!vis[t] && level[t] + 1 == level[s] && e.c == minC)
            {
                q.push(t);
                vis[t] = true;
            }
        }
    }
}

int main()
{
    IOS;

    while (cin >> n >> m)
    {
        FOR(i, 0, MXV) G[i].clear();
        E.clear();
        FOR(i, 0, m)
        {
            int x, y, z;
            cin >> x >> y >> z;
            G[x].emplace_back((int)E.size());
            G[y].emplace_back((int)E.size());
            E.emplace_back(x, y, z);
        }
        bfs1(n);
        bfs2(1);
        cout << level[1] << '\n';
        FOR(i, 0, level[1]) { cout << ans[i] << " \n"[i == level[1] - 1]; }
    }
}
