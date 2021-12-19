#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 3e5 + 5;
const ULL MOD = 10009;
const ULL seed = 31;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);

int p[MXV], d[MXV];
bool ok;
struct DisjointSet
{
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            d[i] = 0;
        }
    }
    int find(int u)
    {
        if (u != p[u])
        {
            int f = p[u];
            p[u] = find(p[u]);
            d[u] = (d[u] + d[f]) & 1;
        }
        return p[u];
    }
    void Union(int u, int v, int dis)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
        {
            if (((d[u] + d[v]) & 1) != dis)
            {
                ok = false;
            }
        }
        else
        {
            p[pv] = pu;
            d[pv] = (d[u] + d[v] + dis) & 1;
        }
    }
};

/*
Usage
DisjointSet djs; // declare
djs.init(int n); // initialize from vertex 0 to vertex n
djs.find(int u) // find the parent of vertex u
djs.Union(int u, int v) // union vertex u and v
*/
int sum[MXN][2];

int main()
{
    DisjointSet djs;
    char s[20];
    int n;
    while (scanf("%d", &n), n)
    {
        djs.init(n);
        ok = true;
        FOR(i, 1, n + 1)
        {
            int j;
            scanf("%s", s);
            scanf("%d", &j);
            scanf("%s", s);
            scanf("%s", s);
            int dis = ((s[0] == 't') ? 0 : 1);
            djs.Union(i, j, dis);
        }
        if (!ok)
        {
            printf("Inconsistent\n");
        }
        else
        {
            memset(sum, 0, sizeof(sum));
            FOR(i,1,n+1)
            {
                int fi = djs.find(i);
                // cout << i << ':' << fi << ' ' << (d[i] & 1) << '\n';
                ++sum[fi][d[i] & 1];
            }
            int ans = 0;
            FOR(i,1,n+1)
            {
                ans+=max(sum[i][0],sum[i][1]);
            }
            printf("%d\n", ans);
        }
    }
}