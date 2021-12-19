#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int N = 30;
struct Edge
{
    Edge(){};
    Edge(int _from, int _to) : from(_from), to(_to) {}
    int from, to;
};
int ans;
bool vis[N];
vector<Edge> E;
vector<int> G[N];

void init()
{
    E.clear();
    for (int i = 0; i < N; i++)
    {
        G[i].clear();
    }
}

void add_Edge(int from, int to)
{
    G[from].push_back(E.size());
    G[to].push_back(E.size());
    E.push_back(Edge(from, to));
}

void dfs(int s, int d)
{
    ans = max(ans, d);
    for (int i = 0; i < (int)G[s].size(); ++i)
    {
        int it = G[s][i];
        if (vis[it])
            continue;
        vis[it] = true;
        Edge &e = E[it];
        dfs(s ^ e.from ^ e.to, d + 1);
        vis[it] = false;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m, n || m)
    {
        init();
        for (int i = 0, x, y; i < m; i++)
        {
            cin >> x >> y;
            add_Edge(x, y);
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            memset(vis, 0, sizeof(vis));
            dfs(i, 0);
        }
        cout << ans << '\n';
    }
}