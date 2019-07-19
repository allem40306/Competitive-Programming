#include <bits/stdc++.h>
using namespace std;
const int ALP = 30;
const int MXN = 1005;
int cnt1, cnt2;
int din[ALP], dout[ALP];
int par[ALP];
vector<string> vs[MXN], ans;
bitset <MXN> vis, used[ALP];

void djsInit()
{
    for(int i = 0; i != ALP; ++i)
    {
        par[i] = i;
    }
}

int Find(int x)
{
    return (x == par[x] ? (x): (par[x] = Find(par[x])));
}

void init(int n)
{
    string s;
    cnt1 = 0;
    cnt2 = 1;
    djsInit();
    memset(din, 0, sizeof(din));
    memset(dout, 0, sizeof(dout));
    vis.reset();
    for(int i = 0; i != ALP; ++i)
    {
        vs[i].clear();
        used[i].reset();
    }
    for(int i = 0, from, to; i != n; ++i)
    {
        cin >> s;
        from = s[0] - 'a';
        to = s[s.size() - 1] - 'a';
        ++din[to]; ++dout[from];
        vs[from].push_back(s);
        vis[from] = vis[to] = true;
        from = Find(from);
        to = Find(to);
        if(from != to)
        {
            par[from] = to;
            ++cnt2;
        }
    }
    for(int i = 0; i != ALP; ++i)
    {
        if(vis[i])
        {
            ++cnt1;
        }
        sort(vs[i].begin(), vs[i].end());
    }
    return;
}

void dfs(int u)
{
    for(int i = 0; i != (int)vs[u].size(); ++i)
    {
        if(used[u][i])
        {
            continue;
        }
        used[u][i] = 1;
        string s = vs[u][i];
        int v = s[s.size() - 1] - 'a';
        dfs(v);
        ans.push_back(s);
    }
}

bool solve()
{
    if(cnt1 != cnt2)
    {
        return false;
    }
    int root, st, pin = 0, pout = 0;
    for(int i = ALP - 1; i >= 0; --i)
    {
        if(vs[i].size())root = i;
        if(dout[i] - din[i] == 1)
        {
            ++pout;
            st = i;
        }
        else if(dout[i] - din[i] == -1)
        {
            ++pin;
        }
        else if(dout[i] - din[i] != 0)
        {
            return false;
        }
        if(pin > 1 || pout > 1)
        {
            return false;
        }
    }
    if(pin != pout)
    {
        return false;
    }
    ans.clear();
    if(pin == 0)
    {
        dfs(root);
    }
    else
    {
        dfs(st);
    }
    return true;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        init(n);
        bool res = solve();
        if(res)
        {
            for(int i = ans.size() - 1; i >= 0; --i)
            {
                cout << ans[i];
                if(i)
                {
                    cout << '.';
                }
            }
            cout << '\n';
        }
        else
        {
            cout << "***\n";
        }
        
    }
}