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
const int MXN = 150;
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
    int from, to, w;
    Edge(){};
    Edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w){};
    bool operator<(const Edge &rhs) const { return w < rhs.w; }
};
string s[MXN];
vector<PII> loc;
vector<Edge> edges;
int dis[MXN][MXN];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int idx)
{
    queue<PII> q;
    q.emplace(loc[idx]);
    memset(dis, -1, sizeof(dis));
    dis[loc[idx].first][loc[idx].second] = 0;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        FOR(i, 0, 4)
        {
            int x = u.first + dir[i][0], y = u.second + dir[i][1];
            if (s[x][y] == '#' || dis[x][y] != -1)
                continue;
            dis[x][y] = dis[u.first][u.second] + 1;
            q.emplace(x, y);
        }
    }
    FOR(j, idx + 1, loc.size())
    {
        edges.emplace_back(idx, j, dis[loc[j].first][loc[j].second]);
    }
}

struct DisjointSet
{
    int p[MXN], sz[MXN];
    void init()
    {
        FOR(i, 0, MXN)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int x) { return p[x] = (p[x] == x ? x : Find(p[x])); }
    bool Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
        {
            swap(x, y);
        }
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }
};

int main()
{
    // IOS;
    int t;
    cin >> t;
    DisjointSet djs;
    FOR(ti, 0, t)
    {
        // cout << ti << '\n';
        int n, m;
        cin >> n >> m >> ws;
        loc.clear();
        edges.clear();
        FOR(i, 0, m)
        {
            getline(cin, s[i]);
            // cout << s[i] << '\n';
            FOR(j, 0, s[i].size())
            {
                // cout << i << ' ' << j << '\n';
                if (isalpha(s[i][j]))
                {
                    loc.emplace_back(i, j);
                }
            }
        }
        FOR(i, 0, loc.size()) { bfs(i); }
        djs.init();
        int ans = 0;
        sort(edges.begin(), edges.end());
        for (auto e : edges)
        {
            if(djs.Union(e.from,e.to))
            {
                ans += e.w;
            }
            // cout << e.from << ' ' << e.to << ' ' << e.w << '\n';
        }
        cout << ans << '\n';
    }
}
