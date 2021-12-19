#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int extgcd(LL a, LL b, LL &x, LL &y)
{
    LL d = a;
    if (b)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}

int main()
{
    int n = 3;
    LL m[10], r[10];
    while (cin >> m[0])
    {
        cin >> m[1] >> m[2] >> r[0] >> r[1] >> r[2];
        LL P = 1, ans = 0;
        for (int i = 0; i < n; ++i)
            P *= m[i];
        for (int i = 0; i < n; ++i)
        {
            LL a = P / m[i], x, y;
            extgcd(a, m[i], x, y);
            ans = (ans + r[i] * a * x) % P;
        }
        ans = (ans % P + P) % P;
        for (int i = 0; i < n; ++i)
        {
            if(ans <= r[i])
            {
                ans += P;
                break;
            }
        }
        cout << ans << '\n';
    }
}