#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;
const int INF = 1e9;
const int MXN = 5e4 + 5;
const int MXV = 55;
const LL MOD = 10009;
const LL seed = 31;
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
vector<int> v, G[MXV], cnt(MXV);
bool vis[MXV];

void dfs(int u)
{
    vis[u] = true;
    cout << '(' << u;
    FOR(i, 0, G[u].size())
    {
        if (!vis[G[u][i]])
        {
            cout << ' ';
            dfs(G[u][i]);
        }
    }
    cout << ')';
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        stringstream ss(s);
        priority_queue<int, vector<int>, greater<int>> pq;
        v.clear();
        fill(cnt.begin(), cnt.end(), 0);
        for (int x; ss >> x;)
        {
            v.push_back(x);
            ++cnt[x];
        }
        int n = (int)v.size() + 1;
        FOR(i, 1, n + 1)
        {
            G[i].clear();
            if (cnt[i] == 0)
            {
                pq.push(i);
            }
        }

        FOR(i, 0, v.size())
        {
            int x = pq.top(), y = v[i];
            pq.pop();
            G[x].push_back(y);
            G[y].push_back(x);
            if (--cnt[y] == 0)
            {
                pq.push(y);
            }
        }
        memset(vis, 0, sizeof(vis));
        dfs(n);
        cout << '\n';
    }
}