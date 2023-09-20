#include <bits/stdc++.h>
using namespace std;
const int MXN = 505;
bool isa[MXN][MXN], hasa[MXN][MXN];
map<string, int> mp;
int mid = 0;

int getId(string s)
{
    if (mp.find(s) == mp.end())
        mp[s] = ++mid;
    return mp[s];
}

int main()
{
    int m, n;
    string a, cmd, b;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> cmd >> b;
        int x = getId(a), y = getId(b);
        if (cmd == "is-a")
            isa[x][y] = true;
        else
            hasa[x][y] = true;
    }
    for (int i = 1; i <= mid; ++i)
        isa[i][i] = true;
    for (int k = 1; k <= mid; ++k)
        for (int i = 1; i <= mid; ++i)
            for (int j = 1; j <= mid; ++j)
            {
                isa[i][j] = isa[i][j] | (isa[i][k] & isa[k][j]);
                hasa[i][j] = hasa[i][j] | (hasa[i][k] & hasa[k][j]);
                hasa[i][j] = hasa[i][j] | (isa[i][k] & hasa[k][j]);
                hasa[i][j] = hasa[i][j] | (hasa[i][k] & isa[k][j]);
            }
    for (int i = 1; i <= n; ++i)
    {
        bool res;
        cin >> a >> cmd >> b;
        int x = getId(a), y = getId(b);
        if (cmd == "is-a")
            res = isa[x][y];
        else
            res = hasa[x][y];
        cout << "Query " << i << ": ";
        if (res)
            cout << "true\n";
        else
            cout << "false\n";
    }
}