/*
source: ABC 140 E Second Sum
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, LL>;

int main()
{
    int n;
    vector<PII> v;
    multiset<int> s;
    cin >> n;
    for(int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end(), greater<PII>());
    s.insert(0); s.insert(0);
    s.insert(n + 1); s.insert(n + 1);
    LL ans = 0;
    for(auto i: v)
    {
        int num = i.first, p = i.second;
        auto it = s.lower_bound(p);
        int R2 = *(++it), R1 = *(--it);
        int L2 = *(--it), L1 = *(--it);
        // cout << num << ' ' << p << '\n';
        // cout << '(' << L1 << ',' << L2 << ')' << '(' << R1 << ',' << R2 << ')' << '\n';
        ans += num * 1LL * (R2 - R1) * (p - L2);
        // cout << ans << ' ';
        ans += num * 1LL * (R1 - p) * (L2 - L1);
        // cout << ans << '\n';
        s.insert(p);
    }
    cout << ans << '\n';
}