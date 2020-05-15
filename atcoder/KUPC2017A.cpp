/*
source: KUPC 2017 A Credits
*/
#include <bits/stdc++.h>
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
using namespace std;
const int MXN = 55;
int main()
{
    IOS;
    int n, m;
    int a[MXN];
    int sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n, greater<int>());
    if(sum < m)
    {
        cout << "-1\n";
        return 0;
    }
    sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += a[i];
        if(sum >= m)
        {
            cout << i + 1 << '\n';
            break;
        }
    }
}