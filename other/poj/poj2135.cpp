#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e4 + 5;
const int MXV = 1e4 + 5;
typedef int T;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);

struct Edge
{
    int v;
    T cost;
    int cap;
    Edge(int _v, int _cost, int _cap) : v(_v), cost(_cost), cap(_cap) {}
};
vector<int> dis(MXV), pre(MXV);
vector<vector<int>> G(MXV);
int n;
vector<Edge> edges;
bitset<MXV> inque;
queue<int> q;
void init(int _n)
{
    n = _n;
    edges.clear();
    for (int i = 0; i <= n; ++i)
    {
        G[i].clear();
    }
}
void addEdge(int u, int v, T cost, int cap)
{
    G[u].push_back((int)edges.size());
    edges.push_back(Edge(v, cost, cap));
    G[v].push_back((int)edges.size());
    edges.push_back(Edge(u, -cost, 0));
}
bool spfa(int s, int t)
{
    FOR(i, 0, MXV) { dis[i] = INF; }
    inque.reset();
    while (!q.empty())
    {
        q.pop();
    }
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inque[u] = false;
        FOR(i, 0, G[u].size())
        {
            Edge &e = edges[G[u][i]];
            if (e.cap > 0 && dis[e.v] > dis[u] + e.cost)
            {
                dis[e.v] = dis[u] + e.cost;
                pre[e.v] = G[u][i];
                if (!inque[e.v])
                {
                    q.push(e.v);
                    inque[e.v] = true;
                }
            }
        }
    }
    return dis[t] != INF;
}
void update(int s, int t, int bottleneck)
{
    for (int u = t; u != s;)
    {
        int pos = pre[u];
        edges[pos].cap -= bottleneck;
        edges[pos ^ 1].cap += bottleneck;
        u = edges[pos ^ 1].v;
    }
}
void sol(int s, int t)
{
    int mnCost = 0;
    while (spfa(s, t))
    {
        update(s, t, 1);
        mnCost += dis[t];
    }
    cout << mnCost << '\n';
}

int main()
{
    IOS;
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        for (int i = 0, f, t, w; i != m; ++i)
        {
            cin >> f >> t >> w;
            addEdge(f, t, w, 1);
            addEdge(t, f, w, 1);
        }
        int s = 0, t = n + 1;
        addEdge(s, 1, 0, 2);
        addEdge(n, t, 0, 2);
        sol(s, t);
    }
}