#include <bits/stdc++.h>
using namespace std;
const int MXN = 150005;

int main()
{
    int t, n, a[MXN];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i != n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0, mn = a[n - 1];
        for(int i = n - 2; i >= 0; --i)
        {
            if(a[i] > mn)
            {
                ++ans;
            }
            mn = min(mn, a[i]);
        }
        cout << ans << '\n';
    }
}