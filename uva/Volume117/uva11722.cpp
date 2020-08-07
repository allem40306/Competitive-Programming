#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
double t1, t2, s1, s2;

double sol(double w) // x+y+w=0, calc right-buttom area
{
    double totArea = (t2 - t1) * (s2 - s1);
    double y1 = t1 + w, y2 = t2 + w;
    if (y2 <= s1)
    {
        return 0;
    }
    if (y1 <= s1)
    {
        if (y2 <= s2)
        {
            return (y2 - s1) * (y2 - s1) * 0.5;
        }
        return ((t2 - (s2 - w)) + (t2 - (s1 - w))) * (s2 - s1) * 0.5;
    }
    if (y1 <= s2)
    {
        if (y2 <= s2)
        {
            return ((t1 - (s1 - w)) + (t2 - (s1 - w))) * (t2 - t1) * 0.5;
        }
        return totArea - (s2 - (t1 + w)) * (s2 - (t1 + w)) * 0.5;
    }
    return totArea;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    FOR(ti, 1, t + 1)
    {
        double w;
        cin >> t1 >> t2 >> s1 >> s2 >> w;
        double ans = sol(w) - sol(-w);
        ans /= (s2 - s1) * (t2 - t1);
        cout << "Case #" << ti << ": ";
        cout << fixed << setprecision(8) << ans << '\n';
    }
}
