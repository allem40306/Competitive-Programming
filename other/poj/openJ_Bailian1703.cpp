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
const int MXV = 2e5 + 5;
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

int p[MXV], sz[MXV];
struct DisjointSet
{
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    bool isSame(int u, int v) { return find(u) == find(v); }
    void Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return;
        }
        if (sz[u] < sz[v])
        {
            swap(u, v);
        }
        sz[u] += sz[v];
        p[v] = u;
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        djs.init(2 * n);
        FOR(i, 0, m)
        {
            char ch;
            int x, y;
            scanf(" %c %d %d", &ch, &x, &y);
            // printf("%c %d %d\n", ch, x, y);
            if (ch == 'D')
            {
                djs.Union(x + n, y);
                djs.Union(x, y + n);
            }
            else
            {
                if (djs.isSame(x + n, y))
                {
                    printf("In different gangs.\n");
                }
                else if (djs.isSame(x, y))
                {
                    printf("In the same gang.\n");
                }
                else
                {
                    printf("Not sure yet.\n");
                }
            }
        }
    }
}