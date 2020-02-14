#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const LL INF = 2e16;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

LL dis(PLL a, PLL b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    IOS;
    LL x, y, ax, ay, bx, by;
    LL xs, ys, t;
    vector<PLL> p;
    cin >> x >> y >> ax >> ay >> bx >> by;
    p.push_back({x, y});
    while(x <= INF && y <= INF)
    {
        x = ax * x + bx;
        y = ay * y + by;
        p.push_back({x, y});
    }
    cin >> xs >> ys >> t;
    PLL loc = make_pair(xs, ys);
    int ans = 0;
    for(int i = 0; i < (int)p.size(); ++i)
    {
        for(int j = i; j < (int)p.size(); ++j)
        {
            LL dL = dis(loc, p[i]);
            LL dR = dis(loc, p[j]);
            LL d = dis(p[i], p[j]);
            if(d + dL <= t || d + dR <= t)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << '\n';
}