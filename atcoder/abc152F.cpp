/*
source: ABC 152 F Tree and Constraints
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
const int MXN = 55;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
vector<PII> G[MXN], cond;
vector<int> route[MXN][MXN];

bool dfs(int s, int t, int u, int p)
{
    if(t == u)
    {
        return true;
    }
    for(auto edge: G[u])
    {
        if(edge.first == p)
        {
            continue;
        }
        if(dfs(s, t, edge.first, u))
        {
            route[s][t].push_back(edge.second);
            return true;
        }
    }
    return false;
}

int main()
{
    // IOS;
    int n, m;
    cin >> n;
    for (int i = 0, x, y; i < n - 1; ++i)
    {
        cin >> x >> y;
        G[x].push_back({y, i});
        G[y].push_back({x, i});
    }
    cin >> m;
    cond.resize(m + 5);
    for (int i = 0; i < m; ++i)
    {
        cin >> cond[i].first >> cond[i].second;
        dfs(cond[i].first, cond[i].second, cond[i].first, -1);
    }
    LL ans = (1LL << (n - 1));
    bitset<MXN> chosen;
    for (int i = 1; i < (1 << m); ++i)
    {
        // cout << i << " here\n";
        chosen.reset();
        for (int j = 0; j < m; ++j)
        {
            if((i >> j) & 1)
            {
                int s = cond[j].first, t = cond[j].second;
                for(auto r: route[s][t])
                {
                    chosen[r] = true;
                }
            }
        }
        int cnt = chosen.count();
        // cout << "cnt:" << cnt << ' ' << (1LL << (n - 1 - cnt)) << '\n';
        if(__builtin_popcount(i) & 1)
        {
            ans -= (1LL << (n - 1 - cnt));
        }
        else
        {
            ans += (1LL << (n - 1 - cnt));
        }
    }
    cout << ans << '\n';
}