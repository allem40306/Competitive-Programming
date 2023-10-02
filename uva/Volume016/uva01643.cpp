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

int main()
{
    IOS;
    int n;
    while (cin >> n, n)
    {
        double a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        double k1 = b1 / a1, k2 = b2 / a2;
        if (k1 > k2)
            swap(k1, k2);

        double L = 0, area = 0, tmp;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            L += tmp;
            area += tmp * tmp;
        }

        double x1 = (k2 + 1) / (k2 - k1) * L;
        double x2 = (k1 + 1) / (k2 - k1) * L;
        double y1 = k1 * x1;
        double y2 = k2 * x2;
        cout << fixed << setprecision(3) << ((x1 * y2) - (x2 * y1) - area) / 2 << '\n';
    }
}
