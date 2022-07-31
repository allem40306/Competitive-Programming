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

struct Data
{
    int b, j;
    bool operator<(const Data &rhs) const { return j > rhs.j; }
};

int main()
{
    IOS;
    int n, ti = 0;
    Data a[1005];
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> a[i].b >> a[i].j;
        sort(a, a + n);
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += a[i].b;
            ans = max(ans, sum + a[i].j);
        }
        cout << "Case " << ++ti << ": " << ans << '\n';
    }
}
