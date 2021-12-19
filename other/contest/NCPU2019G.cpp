#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int tar, root;
typedef pair<int, int> PII;
vector <PII> E;
vector<int> G[N];
bool iscycle;
bitset<N> vis;

void dfs(int x, int eno, int remain)
{
    //cout << x << ' ' << eno << '\n';
    if(remain == 0)
    {
        iscycle = true;
        return;
    }
    vis[x] = true;
    for(auto it: G[x])
    {
        if(it == eno)
            continue;
        int y = E[it].first ^ E[it].second ^ x;
        if(y == root && remain == 1)
        {
            iscycle = true; return;
        }
        if(((1 << y) & tar) == 0 || vis[y])
            continue;
        dfs(y, it, remain - 1);
        if(iscycle)
            return;
    }
    vis[x] = false;
}

int main()
{
    int t, n, m;
    cin >> t;
    while(t--)
    {
        int cnt = 0;
        E.clear();
        cin >> n >> m;
        for(int i = 0; i != N; ++i)
        {
            G[i].clear();
        }
        for(int i = 0, x, y; i != m; ++i)
        {
            cin >> x >> y;
            --x;
            --y;
            G[x].push_back(E.size());
            G[y].push_back(E.size());
            E.push_back({x, y});
        }
        for(tar = 1; tar != (1 << n); ++tar)
        {
//            cout << '\n' << i << "---\n";
            for(int j = 0; j != n; ++j)
            {
                if(((1 << j) & tar) == 0)
                {
                    continue;
                }
                iscycle = false;
                vis.reset();
                //cout << '\n' << tar << ' ' << __builtin_popcount(tar) << '\n';
                root = j;
                dfs(j, -1, __builtin_popcount(tar));
                if(iscycle)
                {
                    //cout << '\n' << tar << "---\n";
                    ++cnt;
                }
                break;
            }
        }
        cout << cnt << '\n';
        if(cnt < 2)
        {
            cout << "n\n";
        }
        else if(cnt == 2)
        {
            cout << "y\n";
        }
        else
        {
            cout << "y: there are at least three cycles\n";
        }
    }
}
