#pragma GCC optimize(2)
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 205;
const int MXV = 0;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);

int n, m;
vector<int> G[MXN], in(MXN), ans(MXN);
bool revTopologySort()
{
    int nn = n;
    while (nn)
    {
        int u;
        for (u = n; u > 0; --u)
        {
            if (in[u] == 0)
            {
                ans[u] = nn--;
                FOR(i, 0, G[u].size()) { --in[G[u][i]]; }
                --in[u];
                break;
            }
        }
        if (u == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        FOR(i, 0, n + 1)
        {
            G[i].clear();
            in[i] = 0;
        }
        FOR(i, 0, m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            ++in[x];
            G[y].push_back(x);
        }
        ans.clear();
        if (revTopologySort())
        {
            FOR(i, 1, n + 1) { cout << ans[i] << " \n"[i == n]; }
        }
        else
        {
            cout << "-1\n";
        }
    }
}