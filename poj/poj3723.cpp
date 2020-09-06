#pragma GCC optimize(2)
#include <algorithm>
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
const int MXV = 2e4 + 5;
typedef long long LL;
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
    int f, t;
    LL w;
    bool operator<(const Edge &rhs) const { return w > rhs.w; }
};

struct DisjointSet
{
    int p[MXV], sz[MXV];
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    bool Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return false;
        }
        if (sz[u] < sz[v])
        {
            swap(u, v);
        }
        sz[u] += sz[v];
        p[v] = u;
        return true;
    }
};

/*
Usage
DisjointSet djs; // declare
djs.init(int n); // initialize from vertex 0 to vertex n
djs.find(int u) // find the parent of vertex u
djs.Union(int u, int v) // union vertex u and v
*/

int main()
{
    int t, n, m, r;
    DisjointSet djs;
    vector<Edge> v;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &n, &m, &r);
        v.clear();
        djs.init(n + m);
        Edge tmp;
        FOR(i, 0, r)
        {
            scanf("%d %d %lld", &tmp.f, &tmp.t, &tmp.w);
            tmp.t += n;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        LL ans = 0, cnt = 0;
        FOR(i, 0, r)
        {
            if (djs.Union(v[i].f, v[i].t))
            {
                ans += v[i].w;
                ++cnt;
            }
        }
        printf("%lld\n", (LL)(n + m) * 10000 - ans);
    }
}