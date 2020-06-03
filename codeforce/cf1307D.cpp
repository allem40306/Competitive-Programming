#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<VI>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 2e5 + 5;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

VVI G(MXV, VI(0, 0));

struct Dijkstra
{
    void init(int n)
    {
        for (int i = 0; i <= n; ++i)
        {
            G[i].clear();
        }
    }

    void addEdge(int from, int to)
    {
        G[from].push_back(to);
        G[to].push_back(from);
    }

    void dijkstra(VI &d, int s)
    {
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : G[u])
            {
                if (d[v] != -1)
                {
                    continue;
                }
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
};

VI d1(MXV, -1), d2(MXV, -1);
bool cmp(int x, int y) { return d1[x] - d2[x] < d1[y] - d2[y]; };

int main()
{
    IOS;
    int n, m, k;
    Dijkstra dijkstra;
    cin >> n >> m >> k;
    dijkstra.init(n);
    VI p(k);
    FOR(i, 0, k) { cin >> p[i]; }
    FOR(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        dijkstra.addEdge(x, y);
    }
    dijkstra.dijkstra(d1, 1);
    dijkstra.dijkstra(d2, n);
    // FOR(i, 1, n + 1) { cout << d1[i] << ' ' << d2[i] << '\n'; }
    sort(p.begin(), p.end(), cmp);
    int ans = 0, tmp = -1e9;
    FOR(i, 0, k)
    {
        int v = p[i];
        ans = max(ans, tmp + d2[v] + 1);
        tmp = max(tmp, d1[v]);
    }
    ans = min(ans, d1[n]);
    cout << ans << '\n';
}