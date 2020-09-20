#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
const LL INF = 1e18;
const int MXV = 1e5 + 5;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<PII> island;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        island.push_back({v[i],i});
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end(), greater<int>());
    sort(island.begin(), island.end(), greater<PII>());
    int tmp = 0, ans = 0;
    bitset<MXV> vis;
    vis.reset();
    for(int i = 0, j = 0; i < (int)v.size(); ++i)
    {
        int cur_height = v[i];
        if(cur_height == 0)
        {
            break;
        }
        while(j != (int)island.size() && island[j].first == cur_height)
        {
            int pos = island[j].second;
            vis[pos] = true;
            ++tmp;
            if(pos - 1 >= 0 && vis[pos - 1])
            {
                --tmp;
            }
            if(pos + 1 < n && vis[pos + 1])
            {
                --tmp;
            }
            ++j;
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}