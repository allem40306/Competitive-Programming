#include <bits/stdc++.h>
using namespace std;
double range[4] = {0.1, 0.3, 0.6, 0.8};
double radio[4] = {0.4, 0.3, 0.2, 0.1};
int main()
{
    int t, n;
    vector<int> v;
    cin >> t;
    while(t--)
    {
        cin >> n;
        v.resize(n);
        for(int i = 0; i != n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        int vi = 0, ans = 0;
        for (int i = 0; i < 4; ++i)
        {
            while(vi != n && v[vi] >= v[floor(double(n) * range[i])])
            {
                ans += ceil(double(v[vi]) * radio[i]);
                ++vi;
            }
        }
        cout << ans << '\n';
    }

}