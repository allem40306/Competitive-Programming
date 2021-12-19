#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 1005;
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

struct Edge
{
    int from, to, w;
};

struct Dijkstra
{
    const int INF = 1000000000;
    int d[MXV], p[MXV];
    vector<Edge> E;
    vector<int> v[MXV];
    bitset<MXV> vis;

    void init()
    {
        fill(d, d + MXV, INF);
        memset(p, 0, sizeof(p));
        E.clear();
        for (int i = 0; i < MXV; i++)
        {
            v[i].clear();
        }
        vis.reset();
    }

    void addEdge(int from, int to, int w)
    {
        v[from].push_back(E.size());
        E.push_back(Edge{from, to, w});
    }

    void dijkstra(int s)
    {
        d[s] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> states;
        vis.reset();
        states.push(MP(d[s], s));
        while (!states.empty())
        {
            PII state = states.top();
            states.pop();
            if (vis[state.second])
            {
                continue;
            }
            vis[state.second] = true;
            for (int u : v[state.second])
            {
                Edge e = E[u];
                if (d[e.to] > d[e.from] + e.w)
                {
                    d[e.to] = d[e.from] + e.w;
                    p[e.to] = e.from;
                    states.push(MP(d[e.to], e.to));
                }
            }
        }
    }
    void sol(int n)
    {
        int ans = 0;
        FOR(i, 1, n + 1)
        {
            if (d[i] > d[ans])
            {
                ans = i;
            }
        }
        cout << ans << ' ' << d[ans] << '\n';
    }
};

/*
Usage
Dijkstra dijkstra; // declare
dijkstra.init();
dijsktra.addEdge(int from, int to, int w); // add a directional Edge
dijkstra.dijkstra(int s) // calculation shortest distance from s
*/

int main()
{
    IOS;
    int t;
    Dijkstra dijkstra;
    cin >> t;
    FOR(ti, 0, t)
    {
        int n;
        cin >> n;
        int f, t, w;
        dijkstra.init();
        while (cin >> f, f != -1)
        {
            cin >> t >> w;
            dijkstra.addEdge(f, t, w);
        }
        dijkstra.dijkstra(0);
        dijkstra.sol(n);
    }
}
