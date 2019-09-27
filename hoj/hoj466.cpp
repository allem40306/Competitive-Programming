#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int t, n;
    int x;
    map<int, int>tb;
    cin >> t;
    while(t--)
    {
        tb.clear();
        cin >> n;
        for(int i = 0; i != n; ++i)
        {
            cin >> x;
            if(tb.find(x) == tb.end())
            {
                tb[x] = 1;
            }
            else
            {
                tb[x] += 1;
            }
        }
        int mx = 0, ans = 0;
        for(auto it: tb)
        {
            if(mx < it.second)
            {
                ans = it.first;
                mx = it.second;
            }
        }
        if(mx > n / 2)
        {
            cout << ans << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
        
    }
}