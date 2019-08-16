#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    int res = 0;
    while(x)
    {
        res += x % 10;
        x /=10;
    }
    return res;
}

int main()
{
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    for(int i = 0, x, y; i != n; ++i)
    {
        cin >> x;
        y = f(x);
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i != n; ++i)
    {
        cout << v[i].second << " \n"[i == n - 1];
    }
}