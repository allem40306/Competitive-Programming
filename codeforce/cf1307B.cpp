#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        bool hasEqual = false;
        cin >> n >> x;
        vector<int> v(n);
        FOR(i, 0, n)
        {
            cin >> v[i];
            if (v[i] == x)
            {
                hasEqual = true;
            }
        }
        int mx = *max_element(v.begin(), v.end());
        if (hasEqual)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << max((x / mx) + 1 * (x % mx != 0), 2) << '\n';
        }
    }
}
