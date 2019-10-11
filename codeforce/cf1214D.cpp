#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<string> strs;
    cin >> n >> m;
    strs.resize(n);
    for(int i = 0; i != m; ++i)
    {
        cin >> strs[i];
    }
    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});
    while(!q.empty())
    {
        auto it = q.front(); q.pop();
        strs[it.first][it.second] = '-';
        if(it.first - 1 >= 0 && strs[it.first - 1][it.second] == '.')
        {
            q.push({it.first - 1, it.second});
        }
        if(it.second - 1 >= 0 && strs[it.first][it.second - 1] == '.')
        {
            q.push({it.first, it.second - 1});
        }
    }
    int ans = 0;
    if(n > 1 && strs[1][0] == '-')
    {
        ++ans;
    }
    if(m > 1 && strs[0][1] == '-')
    {
        ++ans;
    }
    cout << ans << '\n';
}