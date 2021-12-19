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

int p[MXV], sz[MXV], ans[MXV];
struct DisjointSet
{
    void init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = i;
            sz[i] = 1;
            ans[i] = 0;
        }
    }
    int find(int u)
    {
        if (u != p[u])
        {
            int f = p[u];
            p[u] = find(p[u]);
            ans[u] += ans[f];
        }
        return p[u];
    }
    void Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return;
        }
        p[u] = v;
        ans[u] = sz[v];
        sz[v] += sz[u];
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
    int p;
    scanf("%d", &p);
    djs.init(MXV);
    while (p--)
    {
        char ch;
        int x, y;
        scanf(" %c %d", &ch, &x);
        if (ch == 'M')
        {
            scanf(" %d", &y);
            djs.Union(x, y);
        }
        else
        {
            djs.find(x);
            printf("%d\n", ans[x]);
        }
        // printf("%c %d %d\n", ch, x, y);
    }
}