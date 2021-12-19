#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, m;
    cin >> t;
    while(t--)
    {
        cin >> m;
        int ans = 0;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = i; i + j <= m; j++)
            {
                int k = m - i - j;
                if(k < j)
                {
                    break;
                }
                if(i + j > k)
                {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}