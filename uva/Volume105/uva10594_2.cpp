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
    struct Edge
    {
        int u, v;
        T cost, cap;
    };
    int n, pre[MXV], cnt[MXV];
    vector<Edge> edges;
    vector<int> G[MXV];
    T dis[MXV], ansFlow, ansCost;
    bitset<MXV> inque;
    void init(int _n)
    {
        n = _n;
        edges.clear();
        for (int i = 0; i <= n; ++i)
            G[i].clear();
    }
    void addEdge(int u, int v, T cost, T cap)
    {
        G[u].push_back(edges.size());
        edges.push_back({u, v, cost, cap});
        G[v].push_back(edges.size());
        edges.push_back({v, u, -cost, 0});
    }
    bool spfa(int s, int t)
    {
        queue<int> q;
        bool negative = false;
        fill(begin(dis), end(dis), INF);
        fill(begin(pre), end(pre), -1);
        fill(begin(cnt), end(cnt), 0);
        inque.reset();
        dis[s] = 0;
        cnt[s] = 1;
        q.push(s);
        inque[s] = true;
        while (!q.empty() && !negative)
        {
            int u = q.front();
            q.pop();
            inque[u] = false;
            for (int i : G[u])
            {
                Edge &e = edges[i];
                int v = e.v;
                T cost = e.cost, cap = e.cap;
                if (dis[v] > dis[u] + cost && cap > 0)
                {
                    dis[v] = dis[u] + cost;
                    pre[v] = i;
                    if (inque[v])
                        continue;
                    q.push(v);
                    inque[v] = true;
                    ++cnt[v];
                    if (cnt[v] == n + 2)
                    {
                        negative = true;
                        break;
                    }
                }
            }
        }
        return dis[t] != INF;
    }
    T update(int u, T limit)
    {
        if (pre[u] == -1)
            return limit;
        int i = pre[u];
        Edge &e = edges[i];
        LL f = update(e.u, min(limit, e.cap));
        // cout << e.u << ' ' << e.v << ' ' << f << ' ' << e.cost << '\n';
        ansCost += f * e.cost;
        edges[i].cap -= f;
        edges[i ^ 1].cap += f;
        return f;
    }
    void sol(int s, int t, T D)
    {
        ansFlow = ansCost = 0;
        while (spfa(s, t))
        {
            ansFlow += update(t, INF);
            // cout << ansFlow << ' ' << D << '\n';
        }
        if (ansFlow != D)
            cout << "Impossible.\n";
        else
            cout << ansCost << '\n';
    }
};

int main()
{
    IOS;
    MCMF<LL> mcmf;
    int n, m;
    LL d, k;
    int x[5005], y[5005];
    LL z[5005];
    while (cin >> n >> m)
    {
        mcmf.init(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> x[i] >> y[i] >> z[i];
        }
        cin >> d >> k;
        for (int i = 0; i < m; ++i)
        {
            mcmf.addEdge(x[i], y[i], z[i], k);
            mcmf.addEdge(y[i], x[i], z[i], k);
        }
        mcmf.addEdge(0, 1, 0, d);
        mcmf.sol(0, n, d);
    }
}