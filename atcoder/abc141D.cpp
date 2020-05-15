/*
source: ABC 141 D Powerful Discount Tickets
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int n, m;
    LL x;
    priority_queue<LL> pq;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        pq.push(x);
    }
    for(int i = 0; i < m; ++i)
    {
        x = pq.top(); pq.pop();
        pq.push(x / 2);
    }
    LL ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += pq.top(); pq.pop();
    }
    cout << ans << '\n';
}