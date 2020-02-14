#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int t;
    long long a, b, c, r;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> r;
        if(a > b)
        {
            swap(a, b);
        }
        // cout << min(b, c + r) << ' ' << max(a, c - r) << '\n';
        cout << (b - a) - max(min(b, c + r) - max(a, c - r), 0LL) << '\n';
    }
}