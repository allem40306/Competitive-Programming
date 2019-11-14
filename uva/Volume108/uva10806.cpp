#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
const int MXV = 205;
const int INF = 1e9;

template <typename T> struct MCMF
{
    int n, dis[MXV], pre[MXV];
    int cap[MXV][MXV], flow[MXV][MXV];
    struct Edge
    {
        int v;
        T rf;
        int re;
    };
    vector<Edge> edges[MXV];
    bitset<MXV> inque, used[MXV];
    queue<int> q;
    void init(int _n)
    {
        n = _n;
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        for (int i = 0; i <= n; ++i)
        {
            edges[i].clear();
            used[i].reset();
        }
    }
    void addEdge(int u, int v, T rf)
    {
        cap[u][v] = cap[v][u] = rf;
        edges[u].push_back({v, rf, (int)edges[v].size()});
        edges[v].push_back({u, rf, (int)edges[u].size() - 1});
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
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inque[u] = false;
            for (Edge &e : edges[u])
            {
                int v = e.v;
                if (flow[v][u] > 0 && dis[v] > dis[u] + (-e.rf))
                {
                    dis[v] = dis[u] + (-e.rf);
                    pre[v] = u;
                    if (!inque[v])
                    {
                        q.push(v);
                        inque[v] = true;
                    }
                }
                else if (!used[u][v] && cap[u][v] > flow[u][v] &&
                         dis[v] > dis[u] + e.rf)
                {
                    dis[v] = dis[u] + e.rf;
                    pre[v] = u;
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
    void update(int s, int t, int bottleneck)
    {
        for (int u = t; u != s; u = pre[u])
        {
            flow[pre[u]][u] += bottleneck;
            flow[u][pre[u]] -= bottleneck;
            used[pre[u]][u] = used[u][pre[u]] = true;
        }
    }
    void sol(int s, int t)
    {
        int mnCost = 0, mxFlow = 0;
        while (spfa(s, t))
        {
            update(s, t, 1);
            ++mxFlow;
            mnCost += dis[t];
            if (mxFlow >= 2)
            {
                break;
            }
        }
        if (mxFlow < 2)
        {
            cout << "Back to jail\n";
        }
        else
        {
            cout << mnCost << '\n';
        }
    }
};

int main()
{
    // IOS;
    int n, m;
    MCMF<int> mcmf;
    while (cin >> n, n)
    {
        cin >> m;
        mcmf.init(n);
        for(int i = 0, f, t, w; i != m; ++i)
        {
            cin >> f >> t >> w;
            mcmf.addEdge(f, t, w);
        }
        mcmf.sol(n, 1);
    }
}