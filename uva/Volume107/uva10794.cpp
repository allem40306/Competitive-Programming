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

struct Point
{
    double x, y, z;
    Point() {}
    Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    void read() { cin >> x >> y >> z; }
    void output() { cout << x << ' ' << y << ' ' << z << '\n'; }
    Point operator+(const Point &rhs) const
    {
        return Point(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    Point operator-(const Point &rhs) const
    {
        return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    Point operator*(const double &d) const
    {
        return Point(x * d, y * d, z * d);
    }
    Point operator/(const double &d) const
    {
        return Point(x / d, y / d, z / d);
    }
    double dist(const Point &rhs) const
    {
        double res = 0;
        res += (x - rhs.x) * (x - rhs.x);
        res += (y - rhs.y) * (y - rhs.y);
        res += (z - rhs.z) * (z - rhs.z);
        return res;
    }
};

int main()
{
    IOS;
    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti)
    {
        double time;
        Point x1, y1, d1, x2, y2, d2;
        cin >> time;
        x1.read();
        y1.read();
        x2.read();
        y2.read();
        d1 = (y1 - x1) / time;
        d2 = (y2 - x2) / time;
        double L = 0, R = 1e8, m1, m2, f1, f2;
        double ans = x1.dist(x2);
        while (abs(L - R) > 1e-10)
        {
            m1 = (L + R) / 2;
            m2 = (m1 + R) / 2;
            f1 = ((d1 * m1) + x1).dist((d2 * m1) + x2);
            f2 = ((d1 * m2) + x1).dist((d2 * m2) + x2);
            ans = min(ans, min(f1, f2));
            if (f1 < f2)
                R = m2;
            else
                L = m1;
        }
        cout << "Case " << ti << ": ";
        cout << fixed << setprecision(4) << sqrt(ans) << '\n';
    }
}
