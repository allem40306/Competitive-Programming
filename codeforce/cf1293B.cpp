#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n;
    double ans = 0;
    cin >> n;
    while(n != 1)
    {
        ans += 1 / double(n);
        n -= 1;
    }
    cout << ans + 1 << '\n';
}