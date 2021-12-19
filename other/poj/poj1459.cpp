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
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);

template <typename T> struct Dinic
{
    int n, s, t, level[MXV], now[MXV];
    struct Edge
    {
        int v;
        T rf; // rf: residual flow
        int re;
        Edge(int _v, T _rf, int _re) : v(_v), rf(_rf), re(_re) {}
    };
    vector<Edge> e[MXV];
    void init(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i <= n; i++)
        {
            e[i].clear();
        }
    }
    void add_edge(int u, int v, T f)
    {
        e[u].push_back(Edge(v, f, (int)e[v].size()));
        // e[v].push_back(Edge(u, f, (int)e[u].size() - 1));
        // for directional graph
        e[v].push_back(Edge(u, 0, (int)e[u].size() - 1));
    }
    bool bfs()
    {
        fill(level, level + n + 1, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            FOR(i, 0, e[u].size())
            {
                Edge it = e[u][i];
                if (it.rf > 0 && level[it.v] == -1)
                {
                    level[it.v] = level[u] + 1;
                    q.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    T dfs(int u, T limit)
    {
        if (u == t)
            return limit;
        T res = 0;
        while (now[u] < (int)e[u].size())
        {
            Edge &it = e[u][now[u]];
            if (it.rf > 0 && level[it.v] == level[u] + 1)
            {
                T f = dfs(it.v, min(limit, it.rf));
                res += f;
                limit -= f;
                it.rf -= f;
                e[it.v][it.re].rf += f;
                if (limit == 0)
                {
                    return res;
                }
            }
            else
            {
                ++now[u];
            }
        }
        if (!res)
        {
            level[u] = -1;
        }
        return res;
    }
    T flow(T res = 0)
    {
        while (bfs())
        {
            T tmp;
            memset(now, 0, sizeof(now));
            do
            {
                tmp = dfs(s, INF);
                res += tmp;
            } while (tmp);
        }
        return res;
    }
};

/*
usage
Dinic<int> dinic; // declare, flow type is int
dinic.init(n, s, t); // initialize, n vertexs, start from s to t
dinic.add_edge(x, y, z); // add edge from x to y, weight is z
dinic.flow() // calculate max flow
*/

int main()
{
    int n, np, nc, m;
    Dinic<int> dinic;
    while (scanf("%d %d %d %d", &n, &np, &nc, &m) != EOF)
    {
        int s = n, t = n + 1;
        dinic.init(t, s, t);
        int x, y, z;
        FOR(i, 0, m)
        {
            scanf(" (%d,%d)%d", &x, &y, &z);
            dinic.add_edge(x, y, z);
        }
        FOR(i, 0, np)
        {
            scanf(" (%d)%d", &x, &y);
            dinic.add_edge(s, x, y);
        }
        FOR(i, 0, nc)
        {
            scanf(" (%d)%d", &x, &y);
            dinic.add_edge(x, t, y);
        }
        printf("%d\n", dinic.flow());
    }
}