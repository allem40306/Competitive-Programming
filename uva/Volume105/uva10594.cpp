#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LL = long long;
const int MXV = 105;
const LL INF = 1e9;
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

template <typename T> struct MCMF
{
    int n, pre[MXV];
    T dis[MXV], cap[MXV][MXV], flow[MXV][MXV], cost[MXV][MXV];
    vector<int> edges[MXV];
    bitset<MXV> inque;
    queue<int> q;
    void init(int _n)
    {
        n = _n;
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(cost, 0, sizeof(cost));
        for (int i = 0; i <= n; ++i)
        {
            edges[i].clear();
        }
    }
    void addEdge(int u, int v, T c)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
        cost[u][v] = cost[v][u] = c;
    }
    void setCap(T k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j : edges[i])
            {
                cap[i][j] = k;
            }
        }
    }
    bool spfa(int s, int t)
    {
        fill(begin(dis), end(dis), INF);
        inque.reset();
        while (!q.empty())
        {
            q.pop();
        }
        dis[s] = 0;
        q.push(s);
        inque[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inque[u] = false;
            for (int v : edges[u])
            {
                if (flow[v][u] > 0 && dis[v] > dis[u] + (-cost[v][u]))
                {
                    dis[v] = dis[u] + (-cost[v][u]);
                    pre[v] = u;
                    // cout << u << ' ' << v << ' ' << dis[v] << '\n';
                    if (!inque[v])
                    {
                        q.push(v);
                        inque[v] = true;
                    }
                }
                else if (cap[u][v] > flow[u][v] && dis[v] > dis[u] + cost[u][v])
                {
                    dis[v] = dis[u] + cost[u][v];
                    pre[v] = u;
                    // cout << u << ' ' << v << ' ' << dis[v] << ' ' << cost[u][v] << '\n';
                    if (!inque[v])
                    {
                        q.push(v);
                        inque[v] = true;
                    }
                }
            }
        }
        return dis[t] != INF;
    }
    void update(int s, int t, T bottleneck)
    {
        for (int u = t; u != s; u = pre[u])
        {
            flow[pre[u]][u] += bottleneck;
            flow[u][pre[u]] -= bottleneck;
        }
    }
    T findbottleneck(int s, int t)
    {
        T bottleneck = INF;
        for (int u = t; u != s; u = pre[u])
        {
            bottleneck = min(bottleneck, cap[pre[u]][u] - flow[pre[u]][u]);
        }
        return bottleneck;
    }
    void sol(int s, int t, T D)
    {
        T mnCost = 0, mxFlow = 0;
        while (spfa(s, t))
        {
            T bottleneck = findbottleneck(s, t);
            update(s, t, bottleneck);
            mxFlow += bottleneck;
            mnCost += bottleneck * dis[t];
        }
        if (mxFlow != D)
        {
            cout << "Impossible.\n";
        }
        else
        {
            cout << mnCost << '\n';
        }
    }
};

int main()
{
    IOS;
    MCMF<LL> mcmf;
    int n, m;
    LL d, k;
    while (cin >> n >> m)
    {
        mcmf.init(n);
        LL z;
        for (int i = 0, x, y; i < m; ++i)
        {
            cin >> x >> y >> z;
            mcmf.addEdge(x, y, z);
        }
        cin >> d >> k;
        mcmf.setCap(k);
        mcmf.edges[0].push_back(1);
        mcmf.cap[0][1] = d;
        mcmf.sol(0, n, d);
    }
}
