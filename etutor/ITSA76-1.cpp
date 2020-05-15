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
    int n, i, o;
    cin >> n;
    while (n--)
    {
        cin >> i >> o;
        int ans = 0;
        if (i <= 300)
        {
            ans += i * 3 * 100;
        }
        else if (i <= 500)
        {
            ans += i * 3 * 90;
        }
        else if (i <= 1000)
        {
            ans += i * 3 * 75;
        }
        else
        {
            ans += i * 3 * 50;
        }
        
        if (o <= 500)
        {
            ans += o * 6 * 100;
        }
        else if (o <= 1000)
        {
            ans += o * 6 * 90;
        }
        else
        {
            ans += o * 6 * 75;
        }
        cout << ans / 100 << '\n';
    }
}
