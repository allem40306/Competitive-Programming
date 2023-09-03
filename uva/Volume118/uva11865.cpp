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
const int MXN = 65;
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
struct Edge
{
    int v, u, cap, cost;
};
vector<Edge> E, e;
int n, m, c;
vector<int> in(MXN), pre(MXN), id(MXN), vis(MXN);

int CLE(int root, int n, int m, int x)
{
    int res = 0;
    while (1)
    {
        fill(in.begin(), in.end(), INF);
        for (Edge edge : e)
        {
            if (edge.u != edge.v && edge.cap >= x && edge.cost < in[edge.v])
            {
                in[edge.v] = edge.cost;
                pre[edge.v] = edge.u;
            }
        }
        FOR(i, 0, n)
        {
            if (i != root && in[i] == INF)
            {
                return -1;
            }
        }
        int num = 0;
        fill(id.begin(), id.end(), -1);
        fill(vis.begin(), vis.end(), -1);
        in[root] = 0;
        FOR(i, 0, n)
        {
            res += in[i];
            int v = i;
            while (vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
            {
                for (int j = pre[v]; j != v; j = pre[j])
                {
                    id[j] = num;
                }
                id[v] = num++;
            }
        }
        if(num == 0)
        {
            break;
        }
        FOR(i, 0, n)
        {
            if(id[i] == -1)
            {
                id[i] = num++;
            }
        }
        FOR (i, 0, e.size())
        {
            Edge &edge = e[i];
            if(id[edge.u] != id[edge.v])
            {
                edge.cost -= in[edge.v];
            }
            edge.u = id[edge.u];
            edge.v = id[edge.v];
        }
        n = num;
        root = id[root];
    }
    return res;
}

int main()
{
    // IOS;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> c;
        int mx = 0;
        E.resize(m);
        e.resize(m);
        FOR(i, 0, m)
        {
            cin >> E[i].u >> E[i].v >> E[i].cap >> E[i].cost;
            mx = max(mx, E[i].cap);
        }
        int L = 0, R = mx, ans = -1;
        while (L <= R)
        {
            // cout << L << ' ' << R << '\n';
            int M = (L + R) / 2;
            FOR(i, 0, m) { e[i] = E[i]; }
            int tmp = CLE(0, n, m, M);
            if (tmp == -1 || tmp > c)
            {
                R = M - 1;
            }
            else
            {
                L = M + 1;
                ans = M;
            }
        }
        if (ans == -1)
        {
            cout << "streaming not possible.\n";
        } 
        else
        {
            cout << ans << " kbps\n";
        }
    }
}
