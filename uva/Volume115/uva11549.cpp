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

LL next(LL k, int n)
{
    stringstream ss;
    ss << (LL)k * k;
    string s = ss.str();
    if ((int)s.size() > n)
    {
        s = s.substr(0, n);
    }
    stringstream ss2(s);
    LL ret;
    ss2 >> ret;
    return ret;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        LL k;
        cin >> n >> k;
        LL ans = k;
        LL k1 = k, k2 = k;
        do
        {
            k1 = next(k1, n);
            // ans = max(ans, k1);
            k2 = next(k2, n);
            ans = max(ans, k2);
            k2 = next(k2, n);
            ans = max(ans, k2);
        } while (k1 != k2);
        cout << ans << '\n';
    }
}
