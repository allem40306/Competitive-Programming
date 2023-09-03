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
const int MXV = 200000 + 5;
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
    int p[MXV], dis[MXV];
    void init(int n = MXV - 1)
    {
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            dis[i] = 0;
        }
    }
    int find(int u)
    {
        if (u == p[u])
            return u;
        int root = find(p[u]);
        dis[u] += dis[p[u]];
        return p[u] = root;
    }
};

int main()
{
    int t,n;
    cin >> t;
    DisjointSet djs;
    char ch;
    int x, y;
    while (t--)
    {
        cin >> n;
        djs.init(n);
        while (cin >> ch, ch != 'O')
        {
            if (ch == 'E')
            {
                cin >>x;
                djs.find(x);
                cout << djs.dis[x] << '\n';
            }
            else
            {
                cin >> x >> y;
                djs.p[x] = y;
                djs.dis[x] = abs(x - y) % 1000;
            }
        }
    }
}
