/*
source: ABC 118 B Foods Loved by Everyone
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 50;

int main(){
    int n, m;
    int cnt[MXN] = {};
    cin >> n >> m;
    for(int i = 0, k, a; i != n; ++i)
    {
        cin >> k;
        while(k--)
        {
            cin >> a;
            ++cnt[a];
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; ++i)
    {
        if(cnt[i] == n)
        {
            ++ans;
        }
    }
    cout << ans << '\n';
}