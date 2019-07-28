#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<long long> pos, neg;
    cin >> n >> k;
    for(int i = 0, x; i != n; ++i)
    {
        cin >> x;
        if(x == 1)
        {
            continue;
        }
        if(x > 0)
        {
            pos.emplace_back(x);
        }
        else
        {
            neg.emplace_back(x);
        }
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    long long ans = 0, tmp = 0, posMax = 0, negMax = 0;
    if(pos.size()){
        posMax = pos[0] - 1;
        for(int i = 0; i < (int)pos.size();i = i + k)
        {
            tmp = pos[i] - 1;
            ans += tmp;
        }
    }
    if(neg.size())
    {
        negMax = abs(neg[0]);
        for(int i = 0; i < (int)neg.size();i = i + k)
        {
            tmp = abs(neg[i]);
            ans += tmp;
        }   
    }
    ans *= 2;
    ans -= max(posMax, negMax);
    cout << ans << '\n';
}