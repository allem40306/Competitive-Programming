#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    int t;
    long long a, b, c, d;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b >> c >> d;
        long long ans = 1;
        for (long long i = 0; i < c; ++i)
            ans = (ans * (d - i)) % MOD;
        for (long long i = 0; i < a; ++i)
            ans = (ans * (d - c - i)) % MOD;
        for (long long i = 0; i < b; ++i)
            ans = (ans * (d - c - i)) % MOD;
        cout << ans << '\n';
    }
}
