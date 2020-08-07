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

int p[MXV], rela[MXV];
struct DisjointSet
{
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            rela[i] = 0;
        }
    }
    int find(int u)
    {
        if (u != p[u])
        {
            int f = p[u];
            p[u] = find(p[u]);
            rela[u] = (rela[u] + rela[f]) % 3;
        }
        return p[u];
    }
    void Union(int u, int v, int d)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
        {
            return;
        }
        p[pv] = pu;
        rela[pv] = (rela[u] - rela[v] + 3 + (d - 1)) % 3;
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
    DisjointSet djs;
    int n, k;
    scanf("%d%d", &n, &k);
    djs.init(n);
    int ans = 0;
    FOR(i, 0, k)
    {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n || (d == 2 && x == y))
        {
            ++ans;
        }
        else if (djs.find(x) == djs.find(y))
        {
            if ((d == 1 && rela[x] != rela[y]) ||
                (d == 2 && (rela[x] + 1) % 3 != rela[y]))
            {
                ++ans;
            }
        }
        else
        {
            djs.Union(x, y, d);
        }
    }
    printf("%d\n", ans);
}