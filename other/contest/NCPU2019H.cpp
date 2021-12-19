#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long a[N] = {0, 3};
int phi[N];

void phi_table(int n)
{
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for(int i = 2; i != n; ++i)
    {
        if(phi[i])
            continue;
        for(int j = i; j < n; j += i)
        {
            if(!phi[j])
                phi[j] = j;
            phi[j] = phi[j] / i *(i - 1);
        }
    }
}

int main()
{
    phi_table(N);
    for(int i = 2; i != N; ++i)
    {
        a[i] = a[i - 1] + 4 * phi[i];
    }
    int t, x, y;
    cin >> t;
    while(t--)
    {
        cin >> y >> x;
        if(x <= 0 || __gcd(abs(x), abs(y)) != 1)
        {
            cout << 0 << '\n';
            continue;
        }
        if(x == 1 && -1 <= y && y <= 1)
        {
            cout << y + 2 << '\n';
            continue;
        }
        int xx = abs(x), yy = abs(y);
        int mx = max(xx, yy), mn = min(xx, yy);
        long long ans = a[mx - 1];
        int tmp = 0;
        for(int i = 1; i <= mn; ++i)
        {
            if(__gcd(i, mx) == 1)
            {
                ++tmp;
            }
        }
        if(yy == mx)
        {
            if(y < 0)
            {
                ans += tmp;
            }
            else
            {
                ans += 3 * phi[mx] + (phi[mx] - tmp + 1);
            }
        }
        else
        {
            if(y < 0)
            {
                ans += 1 * phi[mx] + (phi[mx] - tmp + 1);
            }
            else
            {
                ans += 2 * phi[mx] + tmp;
            }
        }
        cout << ans << '\n';
    }
}
