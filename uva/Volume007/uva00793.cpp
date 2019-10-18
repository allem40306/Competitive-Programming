#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
#define MP make_pair
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
const int MXV = 1000005;

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
    void Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u == v)
        {
            return;
        }
        if(sz[u] < sz[v])
        {
            swap(u, v);
        }
        sz[u] += sz[v];
        p[v] = u;
    }
};

int main()
{
    IOS;
    static DisjointSet djs;
    int t, n;
    cin >> t;
    while(t--)
    {
        char x;
        int y, z;
        int yes = 0, no = 0;
        string s;
        cin >> n >> ws;
        djs.init(n);
        while(getline(cin, s) && s != "")
        {
            stringstream ss(s);
            ss >> x >> y >> z;
            if(x == 'c')
            {
                djs.Union(y ,z);
            }
            else
            {
                bool res = djs.find(y) == djs.find(z);
                if(res)
                {
                    ++yes;
                }
                else
                {
                    ++no;
                }
            }
        }
        cout << yes << ',' << no << '\n';
        if(t)
        {
            cout << '\n';
        }
    }
}