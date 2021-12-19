#include <bits/stdc++.h>
using namespace std;
const int MXN = 50005;
int main()
{
    int t, n, m, k;
    vector<int> tree[MXN], f, par;
    bitset<MXN> vis;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        par.resize(n + 5);
        par[1] = 1;
        for(int i = 1, m, x; i <= n; ++i)
        {
            tree[i].clear();
            cin >> m;
            while(m--)
            {
                cin >> x;
                tree[i].push_back(x);
                par[x] = i;
            }
        }
        f.resize(m + 5);
        for(int i = 1, x, a; i <= m; ++i)
        {
            f[i] = 1;
            cin >> x;
            while(x--)
            {
                cin >> a;
                f[i] = tree[f[i]][a - 1];
            }
        }
        int ans = 0;
        vis.reset();
        for(int i = 0, x; i != k; ++i)
        {
            cin >> x;
            x = f[x];
            while(!vis[x])
            {
                ++ans;
                vis[x] = 1;
                x = par[x];
            }
        }
        cout << ans << '\n';
    }
}