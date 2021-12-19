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
const int MXN = 0;
const int MXV = 10000;
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
struct DisjointSet
{
    int p[MXV], sz[MXV];
    void init()
    {
        for (int i = 0; i < MXV; i++)
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
map<int, int> tb; //紀錄有幾個點
int id;

void insert(int x)
{
    if (tb.find(x) == tb.end())
    {
        tb[x] = ++id;
    }
}

int main()
{
    IOS;
    DisjointSet djs;
    int ti = 0;
    int x, y;
    while (cin >> x >> y, x != -1 && y != -1)
    {
        bool ok = true;
        id = 0;
        tb.clear();
        djs.init();
        int E = 0; // 紀錄有幾條邊
        while (x || y)
        {
            insert(x);
            insert(y);
            if (!djs.Union(tb[x], tb[y]))
            {
                ok = false;
            }
            ++E;
            cin >> x >> y;
        }
        // cout << E << ' ' << tb.size() << '\n';
        if (E > 0 && E + 1 != (int)tb.size())
        {
            ok = false;
        }
        cout << "Case " << ++ti;
        if (ok)
            cout << " is a tree.\n";
        else
            cout << " is not a tree.\n";
    }
}
