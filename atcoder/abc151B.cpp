/*
source: ABC 151 B Achieve the Goal
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n, m, k;
    cin >> n >> k >> m ;
    int ans = n * m;
    for(int i = 1, x; i < n; ++i)
    {
        cin >> x;
        ans -= x;
    }
    if(ans > k)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << max(0, ans) << '\n';
    }
}