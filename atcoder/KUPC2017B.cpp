/*
source: KUPC 2017 B Camphor Tree
*/
#include <bits/stdc++.h>
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
using namespace std;

int sol(int s, int t)
{
    int ans = 0;
    while(t && s != t)
    {
        ++ans;
        t >>= 1;
    }
    return (s == t ? ans : -1);
}

int main()
{
    IOS;
    int n, s, t;
    cin >> n >> s >> t;
    cout << sol(s, t) << '\n';
}