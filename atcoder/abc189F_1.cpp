#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 2e5 + 5;
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
struct Equation
{
    double x, y;
    Equation() {}
    Equation(double _x, double _y) : x(_x), y(_y) {}
    Equation operator+(const Equation &rhs) const
    {
        return Equation(x + rhs.x, y + rhs.y);
    }
    Equation operator-(const Equation &rhs) const
    {
        return Equation(x - rhs.x, y - rhs.y);
    }
    Equation operator/(double rhs) const { return Equation(x / rhs, y / rhs); }
} dp[MXN], sum[MXN];
bitset<MXN> isA;

int main()
{
    IOS;
    int n, m, k, x;
    cin >> n >> m >> k;
    isA.reset();
    FOR(i, 0, k)
    {
        cin >> x;
        isA[x] = 1;
    }
    FORD(i, n - 1, 0 - 1)
    {
        if (isA[i])
            dp[i] = Equation(1, 0);
        else
            dp[i] = (sum[i + 1] - sum[i + m + 1]) / m + Equation(0, 1);
        sum[i] = sum[i + 1] + dp[i];
    }
    if (abs(dp[0].x - 1.0) < 1e-6)
        cout << "-1\n";
    else
        cout << fixed << setprecision(3) << dp[0].y / (1 - dp[0].x) << '\n';
}
