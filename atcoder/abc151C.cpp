/*
source: ABC 151 C Welcome to AtCoder
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n, m, ta = 0, tp = 0;
    map<int, int> mp;
    string s;
    cin >> n >> m;
    for(int i = 0, p; i < m; ++i)
    {
        cin >> p >> s;
        if(mp.find(p) == mp.end())
        {
            mp[p] = 0;
        }
        if(mp[p] == -1)
        {
            continue;
        }
        if(s == "AC")
        {
            ++ta;
            tp += mp[p];
            mp[p] = -1;
        }
        else
        {
            mp[p] += 1;
        }
    }
    cout << ta << ' ' << tp << '\n';
}