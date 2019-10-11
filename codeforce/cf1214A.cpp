#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, e, mn;
    cin >> n >> d >> e;
    mn = n;
    for(int i = 1; i * d <= n; ++i)
    {
        mn = min(mn, (n - i * d) % e);
    }
    cout << mn << '\n';
}