/*
source: ABC 152 C Low Elements
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

#include <bits/stdc++.h>
using namespace std;

int main()
{
    IOS;
    int n, mn, ans = 0;
    cin >> n;
    mn = n + 5;
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        if(x < mn)
        {
            ++ans;
            mn = x;
        }
    }
    cout << ans << '\n';
}