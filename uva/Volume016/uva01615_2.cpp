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

struct Line
{
    double L, R;
    bool operator<(const Line &rhs) const { return R < rhs.R; }
};

int main()
{
    IOS;
    double L, d;
    int n;
    Line a[100005];
    while (cin >> L)
    {
        cin >> d >> n;
        for (int i = 0; i < n; ++i)
        {
            double x, y;
            cin >> x >> y;
            double r = sqrt(d * d - y * y);
            a[i].L = max(0.0, x - r);
            a[i].R = min(L, x + r);
        }
        sort(a, a + n);
        int ans = 1, R = a[0].R;
        for (int i = 1; i < n; ++i)
        {
            if(a[i].L > R)
            {
                R = a[i].R;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}
