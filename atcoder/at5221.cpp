/*
source: ABC 140 C Maximal Value
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 105;
int main()
{
    int n, ans = 0;
    int a[MXN];
    cin >> n;
    for(int i = 1; i != n; ++i)
    {
        cin >> a[i];
    }
    ans += a[1] + a[n - 1];
    for(int i = 2; i != n; ++i)
    {
        ans += min(a[i], a[i - 1]);
    }
    cout << ans << '\n';
}