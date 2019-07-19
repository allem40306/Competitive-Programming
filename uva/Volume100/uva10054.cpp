#include <bits/stdc++.h>
using namespace std;
const int MXC = 55;
int d[MXC], G[MXC][MXC];
vector<pair<int, int>> ans;

void dfs(int p)
{
    for(int i = 0; i != MXC; ++i)
    {
        if(G[p][i])
        {
            --d[p]; --d[i];
            --G[p][i];
            --G[i][p];
            dfs(i);
            ans.push_back({i, p});
        }
    }
}

int main()
{
    int t, n;
    cin >> t;
    for(int ti = 1; ti <= t; ++ti)
    {
        cin >> n;
        memset(d, 0, sizeof(d));
        memset(G, 0, sizeof(G));
        ans.clear();
        for(int i = 0, x, y; i != n; ++i)
        {
            cin >> x >> y;
            ++d[x]; ++d[y];
            ++G[x][y];
            ++G[y][x];
        }

        bool flag = true;
        for(int i = 0; i != MXC; ++i)
        {
            if(d[i] % 2 != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i = 0; i != MXC; ++i)
            {
                if(d[i])
                {
                    dfs(i);
                    break;
                }
            }
            for(int i = 0; i != MXC; ++i)
            {
                if(d[i])
                {
                    flag = false;
                    break;
                }
            }
        }

        if(ti != 1)
        {
            cout << '\n';
        }
        cout << "Case #" << ti << '\n';
        if(flag)
        {
            for(auto it: ans)
            {
                cout << it.first << ' ' << it.second << '\n';
            }
        }
        else
        {
            cout << "some beads may be lost\n";
        }
    }
}