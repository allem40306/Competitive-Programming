/*
source: ABC 152 D Handstand 2
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
LL cnt[10][10];

int findH(int x)
{
    while(x >= 10)
    {
        x /= 10;
    }
    return x;
}

int main()
{
    IOS;
    int n;
    LL ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int h = findH(i), e = i % 10;
        ans1 += cnt[e][h];
        if(h == e)
        {
            ++ans2;
        }
        // cout << cnt[e][h] << ' ' << h << ' ' << e << '\n';
        ++cnt[h][e];
    }
    // cout << ans1 << ' ' << ans2 << '\n';
    cout << ans1 * 2 + ans2 << '\n';
}