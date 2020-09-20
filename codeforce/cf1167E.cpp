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
const int MXV = 2e5 + 5;
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
vector<int> G[MXV], d(MXV);
vector<int> odd, even;

void print(vector<int> &v)
{
    cout << v.size() << '\n';
    FOR(i, 0, v.size()) cout << v[i] << " \n"[i == (int)v.size() - 1];
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        // cout << n << ' ' << m << '\n';
        FOR(i, 0, n + 1) { G[i].clear(); }
        FOR(i, 0, m)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        queue<int> q;
        fill(d.begin(), d.begin() + n + 5, -1);
        q.push(1);
        d[1] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : G[u])
            {
                // cout << u << "->" << v << '\n';
                if (d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        odd.clear();
        even.clear();
        FOR(i, 1, n + 1)
        {
            // cout << i << ':' << d[i] << '\n';
            if (d[i] & 1)
            {
                odd.PB(i);
            }
            else
            {
                even.PB(i);
            }
        }
        // cout << odd.size() << ' ' << even.size() << '\n';
        if ((int)odd.size() && (int)odd.size() > n / 2)
        {
            print(even);
        }
        else
        {
            print(odd);
        }
    }
}
