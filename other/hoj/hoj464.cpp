#include <bits/stdc++.h>
using namespace std;
const int MXN = 105;
using LL = long long;
struct Loc{
    LL x, y;
    LL dis(Loc rhs)
    {
        return (x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y);
    }
};


int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t, n, m;
    LL k;
    vector<Loc> locs;
    bitset<MXN> vis;
    queue<int> q;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        k *= k;
        locs.resize(n + 5);
        for(int i = 0; i < n; ++i)
        {
            cin >> locs[i].x >> locs[i].y;
        }
        vis.reset();
        for(int i = 0; i < m; ++i)
        {
            vis[i] = true;
            q.push(i);
        }
        int ans = 0;
        while(!q.empty())
        {
            ++ans;
            auto it = q.front(); q.pop();
            for(int i = m; i < n; ++i)
            {
                if(!vis[i] && locs[it].dis(locs[i]) <= k)
                {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        cout << ans << '\n';
    }
}