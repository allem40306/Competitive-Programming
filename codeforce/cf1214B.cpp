#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b, g, n, ans = 0;
    cin >> b >> g >> n;
    for(int i = 0; i <= b; ++i)
    {
        for(int j = 0; j <= g; ++j)
        {
            if(i + j == n)
            {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}